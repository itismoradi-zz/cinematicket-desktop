#include "profile.hpp"
#include "ui_profile.h"
#include <QSqlQuery>
#include <string>

Profile::Profile(QWidget *parent, QString id, QSqlDatabase * db, bool isManager) :
    QMainWindow(parent),
    ID(id),
    isManager(isManager),
    ui(new Ui::Profile)
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

    getInformation();
}

Profile::~Profile()
{
    delete ui;
}

void Profile::getInformation()
{
    if(isManager)
    {
        getManagerInfo();
    }
    else
    {
        getCustomerInfo();
    }
}

void Profile::getCustomerInfo()
{
    QSqlQuery q("select * from customer where userID = "+ID+";");

    if(q.exec())
    {
        while (q.next())
        {
           ui->lbl_name->setText(q.value("userName").toString());
           ui->lbl_email->setText(q.value("email").toString());
           ui->lbl_phone->setText(q.value("phoneNumber").toString());
           ui->lbl_ID->setText(q.value("userID").toString());

           getWallet();

           ui->lbl_status->setText("اطلاعات کاربری استخراج شد");
        }
    }
    else
    {
        ui->lbl_status->setText("به پایگاه داده متصل نیست");
    }
}

void Profile::getManagerInfo()
{
    QSqlQuery q("select * from cinemaManager where managerID = "+ID+";");

    if(q.exec())
    {
        while (q.next())
        {
           ui->lbl_name->setText(q.value("userName").toString());
           ui->lbl_email->setText(q.value("email").toString());
           ui->lbl_phone->setText(q.value("phoneNumber").toString());
           ui->lbl_ID->setText(q.value("managerID").toString());

           getWallet();

           ui->lbl_status->setText("اطلاعات کاربری استخراج شد");
        }
    }
    else
    {
        ui->lbl_status->setText("به پایگاه داده متصل نیست");
    }
}

void Profile::getWallet()
{
    QSqlQuery q("select credit from wallet where userID = "+ID+";");

    if(isManager)
    {
        ui->lbl_credit->setText("حساب مدیر کیف پول ندارد. پول مستقیما به حساب او ساتنا میشود");
    }
    else if(q.exec())
    {
        while (q.next())
        {
            ui->lbl_credit->setText(q.value("credit").toString());
        }
    }
    else
    {
        ui->lbl_status->setText("کیف پول را پیدا نکرد");
    }
}

void Profile::on_pushButton_clicked()
{
    QSqlQuery q("select credit from wallet where userID = "+ID+";");
    int chargeValue = 0;

    if(q.exec())
    {
        while (q.next())
        {
            chargeValue = q.value("credit").toInt();
            chargeValue += 20000;
        }

        QSqlQuery qCharge("update wallet set credit = (:val) where userID = (:i);");
        qCharge.bindValue(":val", chargeValue);
        qCharge.bindValue(":i", ID);

        if(qCharge.exec())
        {
            getWallet();
        }
        else
        {
            ui->lbl_status->setText("در حال حاضر امکان شارژ وجود ندارد");
        }
    }
    else
    {
        ui->lbl_status->setText("کیف پول را پیدا نکرد");
    }
}
