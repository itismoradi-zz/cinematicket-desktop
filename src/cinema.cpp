#include <iostream>
#include "cinema.hpp"

using namespace std;

void Cinema::setName(QString name)
{
    name_ = name;
}
void Cinema::setCap(int cap)
{
    if(cap > 0)
       capacity_ = cap;
}
void Cinema::setCity(QString city)
{
    city_ = city;
}
void Cinema::setStreet(QString street)
{
    street_ = street;
}
void Cinema::setId(int id)
{
   id_ = id;
}
QString Cinema::getName(void)
{
    return name_;
}
int Cinema::getCap(void)
{
    return capacity_;
}
QString Cinema::getCity(void)
{
    return city_;
}
QString Cinema::getStreet(void)
{
    return street_;
}
int Cinema::getId(void)
{
    return id_;
}
