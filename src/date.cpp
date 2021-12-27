#include <iostream>
#include "../include/date.hpp"

using namespace std;

void Date::setId(int id)
{
    dateId=id;

}
void Date::setDate(int date)
{
    dateDate=date;
}
void Date::setMonth(int month)
{
    dateMonth=month;
}
void Date::setYear(int year)
{
    dateYear=year;
}
void Date::setHour(int hour)
{
    dateHour=hour;
}
int Date::getId(void)
{
    return dateId;
}
int Date::getDate(void)
{
    return dateDate;
}
int Date::getMonth(void)
{
    return dateMonth;
}
int Date::getYear(void)
{
    return dateYear;
}
int Date::getHour(void)
{
   return dateHour;
}