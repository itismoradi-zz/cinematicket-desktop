#ifndef CINEMA_H
#define CINEMA_H

class Cinema
{
private:
    Qstring cinemaName;
    int cinemaCapacity;
    Qstring cinemaCity;
    Qstring cinemaStreet;
    int cinemaId;

public:

    Cinema(/* args */);
    void setName(Qstring);
    void setCap(int);
    void setCity(Qstring);
    void setStreet(Qstring);
    void setId(int);
    Qstring getName(void);
    int getCap(void);
    Qstring getCity(void);
    Qstring getStreet(void);
    int getId(void);

    ~Cinema();
};


#endif // CINEMA_H
