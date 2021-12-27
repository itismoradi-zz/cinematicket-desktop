#include <iostream>
#include "../include/cinema.hpp"

using namespace std;

void Cinema::setName(Qstring name)
{
    cinemaName=name;
}
void Cinema::setCap(int cap)
{
    cinemaCapacity=cap;
}
void Cinema::setCity(Qstring city)
{
    cinemaCity=city;
}
void Cinema::setStreet(Qstring street)
{
    cinemaStreet=street;
}
void Cinema::setId(int id)
{
    cinemaId=id;
}
Qstring Cinema::getName(void)
{
    return cinemaName;
}
int Cinema::getCap(void)
{
    return cinemaCapacity;
}
Qstring Cinema::getCity(void);
{
    return cinemaCity;
}
Qstring Cinema::getStreet(void)
{
    return cinemaStreet;
}
int Cinema::getId(void)
{
    return cinemaId;
}