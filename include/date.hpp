#
#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int dateId;
    int dateDate;
    int dateMonth;
    int dateYear;
    int dateHour;

public:
    Date(/* args */);
    void setId(int);
    void setDate(int);
    void setMonth(int);
    void setYear(int);
    void setHour(int);
    int getId(void);
    int getDate(void);
    int getMonth(void);
    int getYear(void);
    int getHour(void);
    ~Date();
};



#endif // DATE_H
