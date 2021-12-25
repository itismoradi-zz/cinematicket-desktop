#ifndef WALLET_H
#define WALLET_H

class Wallet
{
public:
    void increaseCredit(int);
    void setUserName(QString);
    
    int getCredit();
    QString getUserName();

    bool withdraw(int);     // if user's credit is not enough it will return false

private:
    int credit = 0;
    QString userName;   // name of owner

};

#endif // WALLET_H