#include "date.h"
/*******************************************************************************
 * Method date: Class date
 *______________________________________________________________________________
 * Initialize a date at day 0 bc.
 *______________________________________________________________________________
 *  PRE-CONDITIONS
 *      N/A
 *  POST-CONDITIONS
 *      Constructs a default date
 ******************************************************************************/
date::date()
{
    year=0;
    month=0;
    day=0;
}
/*******************************************************************************
*   date();
*    Constructor; Initialize a date at input day
*    Parameters: y - (int) //IN - year
*                m - (int) //IN - month
*                d - (int) //IN - day
*    Return: none
*******************************************************************************/
date::date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
/*******************************************************************************
*   getYear();
*    Accessor; Returns the year
*    Parameters: N/A
*    Return: year (int)
*******************************************************************************/
int date::getYear()
{
    return year;
}
/*******************************************************************************
*   getMonth();
*    Accessor; Returns the month
*    Parameters: N/A
*    Return: month (int)
*******************************************************************************/
int date::getMonth()
{
    return month;
}
/*******************************************************************************
*   getDay();
*    Accessor; Returns the day
*    Parameters: N/A
*    Return: day (int)
*******************************************************************************/
int date::getDay()
{
    return day;
}
/*******************************************************************************
*   operator=();
*    Accessor; assignment operator
*    Parameters: N/A
*    Return: N/A
*******************************************************************************/
void date::operator=(const date d)
{
    year = d.year;
    month = d.month;
    day = d.day;
}
/*******************************************************************************
*   operator<();
*    Accessor; less than operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/
bool operator<(const date r, const date d)
{
    if (r.year==d.year)
    {
        if(r.month==d.month)
        {
            if (r.day==d.day)
                return false;
            else if (r.day<d.day)
                return true;
            else return false;
        }
        else if (r.month < d.month)
            return true;
        else return false;
    }
    else if (r.year<d.year)
        return true;
    else
        return false;
}
/*******************************************************************************
*   operator>();
*    Accessor; greater than operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/
bool operator>(const date r, const date d)
{
    if (r.year==d.year)
    {
        if(r.month==d.month)
        {
            if (r.day==d.day)
                return false;
            else if (r.day>d.day)
                return true;
            else return false;
        }
        else if (r.month > d.month)
            return true;
        else return false;
    }
    else if (r.year>d.year)
        return true;
    else
        return false;
}
/*******************************************************************************
*   operator==();
*    Accessor; equality operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/
bool operator==(const date r, const date d)
{
    if (r.year == d.year)
    {
        if (r.month == d.month)
        {
            if (r.day == d.day)
                return true;
        }
    }
    return false;
}
/*******************************************************************************
*   operator<=();
*    Accessor; <= operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/
bool operator<=(const date r, const date d)
{
    if (r<d | r==d)
        return true;
    return false;
}
/*******************************************************************************
*   operator>=();
*    Accessor; >= operator
*    Parameters: N/A
*    Return: (bool)
*******************************************************************************/

bool operator>=(const date r, const date d)
{
    if (r>d | r==d)
        return true;
    return false;
}
/*******************************************************************************
*   operator<<();
*    Accessor; iostream overloader, can output dates
*    Parameters: N/A
*    Return: (ostream)
*******************************************************************************/
ostream& operator<<(ostream& out, const date& d)
{
    out<< "["<<d.month<<"/"<<d.day<<"/"<<d.year<<"]";
    //out<< "[Year: "<< d.year<< " Month: "<< d.month<< " Day: "<< d.day<<"]";
    return out;
}
/*******************************************************************************
*   setYear();
*    Mutator; sets new year
*    Parameters: y (int) //IN - year
*    Return: N/A
*******************************************************************************/
void date::setYear(int y)
{
    if (y<0)
        y=0;
    year = y;
}
/*******************************************************************************
*   setMonth();
*    Mutator; sets new month
*    Parameters: m (int) //IN - month
*    Return: N/A
*******************************************************************************/
void date::setMonth(int m)
{
    if (m<=0)
        m=1;
    else if (m>=13)
        m=12;
    month = m;
}
/*******************************************************************************
*   setDay();
*    Mutator; sets new day
*    Parameters: d (int) //IN - day
*    Return: N/A
*******************************************************************************/
void date::setDay(int d)
{
    if (d<=0)
        d=1;
    else if (d>32)
        d=31;
    day = d;
}
