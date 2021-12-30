#include "account.hpp"

Account::Account(QString username, QString password)
{
    changeUsername(username);
    changePassword(password);
}

Account::Account(QString username, QString password, QString name, QString email, QString phoneNumber) // user wants to log in
{
    changeUsername(username);
    changePassword(password);
    setName(name);
    setEmail(email);
    setPhoneNumber(phoneNumber);
}

bool Account::setName(QString name) // name can not have more than 20 characters
{
    if (name.length() == 0 || 20 < name.length())
    {
        return false;
    }
    else
    {
        name_ = name;
        return true;
    }
}

void Account::setEmail(QString email)
{
    email_ = email;
}

void Account::setPhoneNumber(QString phoneNumber)
{
    phoneNumber_ = phoneNumber;
}

QString Account::name()
{
    return name_;
}

QString Account::email()
{
    return email_;
}

QString Account::phoneNumber()
{
    return phoneNumber_;
}

bool Account::changeUsername(QString username)
{
    if (username.isEmpty())
    {
        return false;
    }

    //    if()   //زheck the database for unique username
    //    {
    //        return false;
    //    }

    username_ = username;
    return true;
}

QString Account::username()
{
    return username_;
}

bool Account::changePassword(QString password) 
{
    if (password.isEmpty())
    {
        return false;
    }
    else if (password.length() <= 3 || 20 <= password.length()) // number of password characters should be betweeen 3 to 20 characters
    {
        return false;
    }
    for (QString s : oldPasswords_)
    {
        if (s == password)
        {
            return false; // the new password must not have been used before
        }
    }

    oldPasswords_.push_back(password_);
    password_ = password;
    return true;
}
