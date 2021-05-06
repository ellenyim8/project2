#ifndef DATE_H
#define DATE_H
#include "iostream"
using namespace std;

class date
{
public:
    /**************
    **CONSTRUCTOR**
    **************/
    date();
    date(int, int, int);
    /************
    **ACCESSORS**
    ************/
    int getYear();
    int getMonth();
    int getDay();
    void operator=(const date);
    friend bool operator<(const date,const date);
    friend bool operator>(const date,const date);
    friend bool operator==(const date,const date);
    friend bool operator<=(const date,const date);
    friend bool operator>=(const date,const date);
    friend ostream& operator<<(ostream&, const date&);
    /***********
    **MUTATORS**
    ***********/
    void setYear(int);
    void setMonth(int);
    void setDay(int);
private:
    int year;
    int month;
    int day;
};
/*******************************************************************************
* Date Class
*   This class is an object that holds three parameters, ints for the year, month
* and day.
*******************************************************************************/

/**************
**CONSTRUCTOR**
**************/

/*******************************************************************************
*   date();
*    Constructor; Initialize a date at day 0 bc.
*    Parameters: N/A
*    Return: none
*******************************************************************************/

/*******************************************************************************
*   date();
*    Constructor; Initialize a date at input day
*    Parameters: y - (int) //IN - year
*                m - (int) //IN - month
*                d - (int) //IN - day
*    Return: none
*******************************************************************************/

/************
**ACCESSORS**
************/

/*******************************************************************************
*   getYear();
*    Accessor; Returns the year
*    Parameters: N/A
*    Return: year (int)
*******************************************************************************/

/*******************************************************************************
*   getMonth();
*    Accessor; Returns the month
*    Parameters: N/A
*    Return: month (int)
*******************************************************************************/

/*******************************************************************************
*   getDay();
*    Accessor; Returns the day
*    Parameters: N/A
*    Return: day (int)
*******************************************************************************/

/*******************************************************************************
*   operator=();
*    Accessor; assignment operator
*    Parameters: N/A
*    Return: N/A
*******************************************************************************/

/*******************************************************************************
*   operator<();
*    Accessor; less than operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

/*******************************************************************************
*   operator>();
*    Accessor; greater than operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

/*******************************************************************************
*   operator==();
*    Accessor; equality operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

/*******************************************************************************
*   operator<=();
*    Accessor; <= operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

/*******************************************************************************
*   operator>=();
*    Accessor; >= operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

/*******************************************************************************
*   operator<<();
*    Accessor; iostream overloader, can output dates
*    Parameters: N/A
*    Return: (ostream)
*******************************************************************************/

/***********
**MUTATORS**
***********/

/*******************************************************************************
*   setYear();
*    Mutator; sets new year
*    Parameters: y (int) //IN - year
*    Return: N/A
*******************************************************************************/

/*******************************************************************************
*   setMonth();
*    Mutator; sets new month
*    Parameters: m (int) //IN - month
*    Return: N/A
*******************************************************************************/

/*******************************************************************************
*   setDay();
*    Mutator; sets new day
*    Parameters: d (int) //IN - day
*    Return: N/A
*******************************************************************************/
#endif // DATE_H
