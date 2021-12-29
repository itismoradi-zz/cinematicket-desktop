#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QVector>
#include "wallet.hpp"

class ACCOUNT
{
public:
    ACCOUNT(QString, QString);

    bool changeUsername(QString);
    QString username();
    QString operator~() {return username();}

    bool changePassword(QString);
    bool operator *(QString password) {return changePassword(password);}
    bool checkPassword(QString);
    bool operator ==(QString password) {return checkPassword(password);}
private:
    QString username_;
    QString password_;  //should be saved as a hash
    QVector <QString> oldPasswords_;     //old used passwords can't be used as new password
    Wallet wallet;
};

#endif
