#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString, QString, QString);
    QString name();
    QString email();
    QString phoneNumber();
private:
    QString name_;
    QString email_;         //example@gmail.com
    QString phoneNumber_;   //pattern : +989124444444

    void setName(QString);
    void setEmail(QString);
    void setPhoneNumber(QString);
};

#endif
