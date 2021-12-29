#include "wallet.hpp"

Wallet::Wallet()
{
    credit_ = 0;
}

bool Wallet::charge(unsigned int amount)
{
    credit_ += amount;

    Statement statement;
    statement.operationType = OperationType::CHARGE;
    statement.operationNumber = amount;
    statement.credit = credit_;
    //set dateTime to system dateTime
    statement_.push_back(statement);

    return true;
}

int Wallet::Credit()
{
    Statement statement;
    statement.operationType = OperationType::CHECK;
    statement.operationNumber = 0;
    statement.credit = credit_;
    //set dateTime to system dateTime
    statement_.push_back(statement);
    return credit_;
}

bool Wallet::withdraw(unsigned int amount)
{
    if (amount >= credit_)   // checks if user have enough credit
    {
        credit_ -= amount;

        Statement statement;
        statement.operationType = OperationType::WITHDRAW;
        statement.operationNumber = amount;
        statement.credit = credit_;
        //set dateTime to system dateTime
        statement_.push_back(statement);

        return true;
    }
    else
    {
        return false;
    }
}
