#ifndef CINEMA_H
#define CINEMA_H

#include <QString>

class Cinema
{
private:
    QString cinemaName;
    int cinemaCapacity;
    QString cinemaCity;
    QString cinemaStreet;
    int cinemaId;

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
