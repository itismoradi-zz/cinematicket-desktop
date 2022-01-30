#include "signup.hpp"
#include "ui_signup.h"
#include "login.hpp"
#include <QString>
#include <QSqlQuery>

signUp::signUp(QWidget *parent, QSqlDatabase * db) :
    QMainWindow(parent),
    ui(new Ui::signUp)
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
}

signUp::~signUp()
{
    delete ui;
}

void signUp::signUpCustomer()
{
    QString username, email, phone, password, ID;

    username = ui->lineEdit_name->text();
    email = ui->lineEdit_email->text();
    phone = ui->lineEdit_phone->text();
    password = ui->lineEdit_password->text();
    ID = ui->lineEdit_ID->text();

    if(db->open())
    {
        QSqlQuery q;
        q.prepare("INSERT INTO customer(userName, email, phoneNumber, password, userID) "
                  "VALUES( :n, :e, :p, :ps, :i );");

        q.bindValue(":n", username);
        q.bindValue(":e", email);
        q.bindValue(":p", phone);
        q.bindValue(":ps", password);
        q.bindValue(":i", ID);

        if(q.exec())
        {
            ui->lbl_status->setText("حساب بیننده برای شما ساخته شد");
        }
        else
        {
           ui->lbl_status->setText("اطلاعات غیر مجاز وارد شده است");
        }
    }
    else
    {
        ui->lbl_status->setText("به پایگاه داده متصل نیست");
    }
}

void signUp::signUpManager()
{
    QString username, email, phone, password, ID;

    username = ui->lineEdit_name->text();
    email = ui->lineEdit_email->text();
    phone = ui->lineEdit_phone->text();
    password = ui->lineEdit_password->text();
    ID = ui->lineEdit_ID->text();

    if(db->open())
    {
        QSqlQuery q;
        q.prepare("INSERT INTO cinemaManager(userName, email, phoneNumber, managerID, password) "
                  "VALUES( :n, :e, :p, :i, :ps );");

        q.bindValue(":n", username);
        q.bindValue(":e", email);
        q.bindValue(":p", phone);
        q.bindValue(":i", ID);
        q.bindValue(":ps", password);

        if(q.exec())
        {
            ui->lbl_status->setText("حساب مدیر سینما برای شما ساخته شد");
        }
        else
        {
           ui->lbl_status->setText("اطلاعات غیر مجاز وارد شده است");
        }
    }
    else
    {
        ui->lbl_status->setText("به پایگاه داده متصل نیست");
    }
}

void signUp::on_pushButton_clicked()
{
    this->close();
}

void signUp::on_pushButton_2_clicked()
{
    if(ui->radiobtn_costumer->isChecked())
    {
        signUpCustomer();
    }
    else if(ui->radiobtn_manager->isChecked())
    {
        signUpManager();
    }
    else
    {
         ui->lbl_status->setText("نوع حساب خود را مشخص کنید");
    }
}
