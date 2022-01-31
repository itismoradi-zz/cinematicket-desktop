#include "cinemamovie.hpp"
#include "ui_cinemamovie.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIcon>
#include <QPixmap>
#include <QDebug>

CinemaMovie::CinemaMovie(QWidget *parent, QString id, QSqlDatabase * db, bool isManager) :
    QDialog(parent),
    userID(id),
    isManager(isManager),
    ui(new Ui::CinemaMovie)
{
    this->db = db;
    ui->setupUi(this);

    if(db->open())
    {
        ui->lbl_status->setText("متصل به پایگاه داده");
    }
    else
    {
        ui->lbl_status->setText("پایگاه داده یافت نشد");
    }

    getDataFromDB();
    setComboBoxs();
}

CinemaMovie::~CinemaMovie()
{
    delete ui;
}

void CinemaMovie::on_btn_profile_clicked()
{
    userProfileWindow = new Profile(this, userID, db, isManager);
    userProfileWindow->show();
}

void CinemaMovie::getDataFromDB()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * q = new QSqlQuery;

    q->prepare("select * from cinema;");
    q->exec();
    modal->setQuery(*q);
    ui->tableView_cinema->setModel(modal);
    ui->tableView_cinema->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //------------

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery * q2 = new QSqlQuery;

    q2->prepare("select * from movie;");
    q2->exec();
    modal2->setQuery(*q2);
    ui->tableView_Movie->setModel(modal2);
    ui->tableView_Movie->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void CinemaMovie::setComboBoxs()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * q = new QSqlQuery;

    q->prepare("select id from movie;");
    q->exec();
    modal->setQuery(*q);
    ui->comboBox_Movie->setModel(modal);

    //------------

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery * q2 = new QSqlQuery;

    q2->prepare("select cinemaID from cinema;");
    q2->exec();
    modal2->setQuery(*q2);
    ui->comboBox_cinema->setModel(modal2);

    //------------

    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery * q3 = new QSqlQuery;

    q3->prepare("select id from date;");
    q3->exec();
    modal3->setQuery(*q3);
    ui->comboBox_date->setModel(modal3);
}


void CinemaMovie::on_btn_search_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * q = new QSqlQuery;
    QString movie, cinema, date;

    movie = ui->comboBox_Movie->currentText();
    cinema = ui->comboBox_cinema->currentText();
    date = ui->comboBox_date->currentText();

    q->prepare("select seatNumber from ticket where movieID = :m and cinemaID = :c and dateID = :d;");
    q->bindValue(":m", movie);
    q->bindValue(":c", cinema);
    q->bindValue(":d", date);
    if(q->exec())
    {
        modal->setQuery(*q);
        ui->comboBox_seat->setModel(modal);
    }
    else
    {
        ui->lbl_status->setText("این بلیت یافت نشد");
    }

    if(ui->comboBox_seat->currentText() == "")
    {
        ui->lbl_status->setText("صندلی خالی پیدا نشد");
    }
}

void CinemaMovie::on_comboBox_seat_activated(const QString & seat)
{
    QSqlQuery * q = new QSqlQuery;
    QString movie, cinema, date;

    movie = ui->comboBox_Movie->currentText();
    cinema = ui->comboBox_cinema->currentText();
    date = ui->comboBox_date->currentText();

    q->prepare("select price from ticket where movieID = :m and cinemaID = :c and dateID = :d and seatNumber = :s;");
    q->bindValue(":m", movie);
    q->bindValue(":c", cinema);
    q->bindValue(":d", date);
    q->bindValue(":s", seat);

    if(q->exec())
    {
        q->next();
        ui->lbl_price->setText(q->value("price").toString());
    }
    else
    {
        ui->lbl_status->setText("قیمت بلیت پیدا نشد");
    }
}

void CinemaMovie::on_btn_buyTicket_clicked()
{
    if(ui->lbl_price->text().toInt() == 0)
    {
        ui->lbl_status->setText("لطفا یک بلیت را انتخاب نمایید");
        return;
    }

    //check user id exist in tcketnumbers table
    QSqlQuery * q = new QSqlQuery;

    q->prepare("select userID from ticketNumbers where userID = :id;");
    q->bindValue(":id", userID);

    if(q->exec())
    {
        int count = 0;

        while(q->next())
        {
            count++;
        }

        if(count < 1)
        {
            q->prepare("insert into ticketNumbers (userID) values(:id);");
            q->bindValue(":id", userID);
            q->exec();
        }
    }


    //check user tickets
    q->prepare("select * from ticketNumbers where userID = :id and ticketID is not null;");
    q->bindValue(":id", userID);

    if(q->exec())   //user has one ticket
    {
        int count = 0;

        while(q->next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->lbl_status->setText("شما قبلا بلیت خریده اید");
            return;
        }
    }

    //user has not any ticket

    QString movie = ui->comboBox_Movie->currentText();
    QString cinema = ui->comboBox_cinema->currentText();
    QString date = ui->comboBox_date->currentText();
    QString seat = ui->comboBox_seat->currentText();

    //find ticket id
    QSqlQuery * q2 = new QSqlQuery;
    q2->prepare("update ticketNumbers set ticketID = ( select ticketID from ticket where movieID = :m and "
                "cinemaID = :c and dateID = :d and seatNumber = :s) where userID = :id;");
    q2->bindValue(":m", movie);
    q2->bindValue(":c", cinema);
    q2->bindValue(":d", date);
    q2->bindValue(":s", seat);
    q2->bindValue(":id",  userID);

    if(q2->exec())  //found selected ticket
    {
        ui->lbl_status->setText("بلیت شما خریداری شد");
    }
    else
    {
        ui->lbl_status->setText("این بلیت یافت نشد");
        return;
    }
}


