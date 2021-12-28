#include "user.hpp"

User::User(QString name, QString email, QString phoneNumber)
{
    setName(name);
    setEmail(email);
    setPhoneNumber(phoneNumber);
}

QString User::name()
{
    return name_;
}

QString User::email()
{
    return email_;
}

QString User::phoneNumber()
{
    return phoneNumber_;
}

void User::setName(QString name)
{
    name_ = name;
}

void User::setEmail(QString email)
{
    email_ = email;
}

void User::setPhoneNumber(QString phoneNumber)
{
    phoneNumber_ = phoneNumber;
}
