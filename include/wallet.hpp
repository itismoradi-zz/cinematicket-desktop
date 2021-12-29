#ifndef WALLET_H
#define WALLET_H

#include <QString>
#include <array>
#include <QVector>
#include <QDateTime>

enum class OperationType {CHECK, CHARGE, WITHDRAW};

struct Statement
{
    OperationType operationType;
    unsigned int operationNumber = 0;
    unsigned int credit;
    QDateTime dateTime;
};

class Wallet
{
public:
    Wallet();
    int Credit();
    bool charge(unsigned int);
    bool operator <<(unsigned int amount) {return charge(amount);}
    bool withdraw(unsigned int);     // if user's credit is not enough it will return false
    bool operator >>(unsigned int amount) {return withdraw(amount);}

private:
    unsigned int credit_;
    QVector <Statement> statement_;
};

#endif // WALLET_H
