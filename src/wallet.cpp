#include "../include/wallet.hpp"

void Wallet::increaseCredit(int amount)
{
    credit = credit+= + amount;
}
void Wallet::setUserName(QString name)
{
    userName = name;
}

int Wallet::getCredit()
{
    return credit;
}
QString Wallet::getUserName()
{
    return userName;
}

bool Wallet::withdraw(int amount)
{
    if (amount >= credit)   // checks if user have enough credit
    {
        credit = credit - amount;
        return true;
    }
    else
    {
        return false;
    }
}