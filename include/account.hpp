#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QVector>
#include "wallet.hpp"

class Account
{
public:
    Account(QString, QString);
    Account(QString, QString, QString, QString, QString);   // user wants to log in

    QString username();
    QString operator~() {return username();}
    QString name();
    QString email();
    QString phoneNumber();

    bool setName(QString);  // name can not have more than 20 characters
    void setEmail(QString);
    void setPhoneNumber(QString);   

    bool changeUsername(QString);
    bool changePassword(QString);   // password characters should be betweeen 3 to 20 characters
    bool operator *(QString password) {return changePassword(password);}
    bool checkPassword(QString);
    bool operator ==(QString password) {return checkPassword(password);}

private:
    QString username_;  // name can not have more than 20 characters
    QString password_;  // should be saved as a hash
    QVector <QString> oldPasswords_;     // old passwords can't be used as new password
    Wallet wallet;
    QString name_;
    QString email_;         // example@gmail.com
    QString phoneNumber_;   // pattern : +989124444444
};

#endif
