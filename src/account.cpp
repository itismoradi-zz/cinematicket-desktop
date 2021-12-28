#include "account.hpp"

ACCOUNT::ACCOUNT(QString username, QString password)
{
    changeUsername(username);
    changePassword(password);
}

bool ACCOUNT::changeUsername(QString username)
{
    if(username.isEmpty())
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

QString ACCOUNT::username()
{
    return username_;
}

bool ACCOUNT::changePassword(QString password)
{
    if(password.isEmpty())
    {
        return false;
    }

    for(QString s : oldPasswords_)
    {
        if(s == password)
        {
            return false;   //the new password must not have been used before
        }
    }

    oldPasswords_.push_back(password_);
    password_ = password;
    return true;
}
