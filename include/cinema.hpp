#ifndef CINEMA_H
#define CINEMA_H

#include <QString>

class Cinema
{
private:
    QString name_;
    int capacity_;
    QString city_;
    QString street_;
    int id_;

public:

    Cinema(/* args */);
    void setName(QString);
    void setCap(int);
    void setCity(QString);
    void setStreet(QString);
    void setId(int);
    QString getName(void);
    int getCap(void);
    QString getCity(void);
    QString getStreet(void);
    int getId(void);

    ~Cinema();
};


#endif // CINEMA_H
