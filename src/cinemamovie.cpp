#include "cinemamovie.hpp"
#include "ui_cinemamovie.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIcon>
#include <QPixmap>

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

