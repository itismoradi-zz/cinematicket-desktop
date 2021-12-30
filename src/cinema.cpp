#include <iostream>
#include "../include/cinema.hpp"

using namespace std;

void Cinema::setName(QString name)
{
    bool check;
    for(int i=0;i<=name.length();i++)
    {
        QChar ch=name[i];
        if((ch>=97 && ch<=122) || (ch>=65 && ch<=90))
            check=true;
        else
            check=false;
    }
    if(check==true)
        cinemaName=name;
}
void Cinema::setCap(int cap)
{
    if(cap > 0)
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
