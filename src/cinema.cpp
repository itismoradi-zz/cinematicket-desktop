#include <iostream>
#include "../include/cinema.hpp"

using namespace std;

void Cinema::setName(QString name)
{
    cinemaName=name;
}
void Cinema::setCap(int cap)
{
    cinemaCapacity=cap;
}
void Cinema::setCity(QString city)
{
    cinemaCity=city;
}
void Cinema::setStreet(QString street)
{
    cinemaStreet=street;
}
void Cinema::setId(int id)
{
    cinemaId=id;
}
QString Cinema::getName(void)
{
    return cinemaName;
}
int Cinema::getCap(void)
{
    return cinemaCapacity;
}
QString Cinema::getCity(void)
{
    return cinemaCity;
}
QString Cinema::getStreet(void)
{
    return cinemaStreet;
}
int Cinema::getId(void)
{
    return cinemaId;
}
