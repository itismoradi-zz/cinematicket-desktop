#include "login.hpp"
#include "ui_login.h"
#include <QString>
#include <QSqlQuery>
#include "cinemamovie.hpp"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../cinemaTicket.db");

    if(db.open())
    {
        ui->lbl_status->setText("متصل به پایگاه داده");
    }
    else
    {
        ui->lbl_status->setText("پایگاه داده یافت نشد");
    }
}

login::~login()
{
    delete ui;
}

void login::logIn(QString username, QString password)
{
    QSqlQuery q;
    QSqlQuery q2;

    if(q.exec("select * from customer where userID = '"+username+"' and password = '"+password+"';"))
    {
        int count = 0;

        while(q.next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->lbl_status->setText("welcome");
            this->hide();
            CinemaMovie cmWindow(this, username, &db, false);   //is costumer
            cmWindow.setModal(true);
            cmWindow.exec();
        }
        else
        {
           ui->lbl_status->setText("مشکل در ورود به عنوان بیننده");
        }
    }
    if(q2.exec("select * from cinemaManager where managerID = '"+username+"' and password = '"+password+"';"))
    {
        int count = 0;

        while(q2.next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->lbl_status->setText("welcome");
            this->hide();
            CinemaMovie cmWindow(this, username, &db, true);   //is manager
            cmWindow.setModal(true);
            cmWindow.exec();
        }
        else
        {
           ui->lbl_status->setText("مشکل در ورود به عنوان مدیر");
        }
    }
    else
    {
       ui->lbl_status->setText("شناسه کاربری یا گذرواژه اشتباه است");
    }
}

void login::on_pushButton_clicked()
{
    QString username, password;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(username.isEmpty())
    {
        ui->lbl_status->setText("شناسه کاربری خالی است");
        return;
    }
    else if(password.isEmpty())
    {
        ui->lbl_status->setText("گذرواژه خالی است");
        return;
    }

    if(db.open())
    {
        logIn(username, password);
    }
    else
    {
        ui->lbl_status->setText("به پایگاه داده متصل نیست");
    }
}

void login::on_pushButton_signUp_clicked()
{
    signUpWindow = new signUp(this, &db);
    signUpWindow->show();
}
