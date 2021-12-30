#include <iostream>
#include "../include/date.hpp"

using namespace std;

void Date::setId(int id)
{
    dateId=id;

}
void Date::setDate(int date)
{
    if(date>=1 && date<=31)
        dateDate=date;
}
void Date::setMonth(int month)
{
    if(month>=1 && month<=12)
        dateMonth=month;
}
void Date::setYear(int year)
{
    if(year<=2022)
        dateYear=year;
}
void Date::setHour(int hour)
{
    if(hour>=1 && hour<=24)
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
