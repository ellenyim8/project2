#include "souvenir.h"

/****************************************************
 * Souvenir()
 *
 * default constructor; initialize empty constructor
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: none
****************************************************/
Souvenir::Souvenir()
{
    item = "";
    price = 0;
}

/****************************************************
 * Souvenir(string n, double p)
 *
 * constructor; initializes member item and price
 * with parameters
 * -------------------------------------------------
 *  Parameters: (string) n, (double) p
 * -------------------------------------------------
 *  Returns: nothing
****************************************************/
Souvenir::Souvenir(string n, double p)
{
    item = n;
    price = p;
}

/****************************************************
 * void set_item(string name)
 *
 * mutator; sets parametized string with private
 * member string item
 * -------------------------------------------------
 *  Parameters: (string) name
 * -------------------------------------------------
 *  Returns: none
****************************************************/
void Souvenir::set_item(string name)
{
    item = name;
}

/****************************************************
 * void set_price(double p)
 *
 * mutator; sets parametized double with private
 * member double price
 * -------------------------------------------------
 *  Parameters: (double) p
 * -------------------------------------------------
 *  Returns: none
****************************************************/
void Souvenir::set_price(double p)
{
    price = p;
}

/****************************************************
 * string get_item() const
 *
 * accessor; returns private member item
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: string
****************************************************/
string Souvenir::get_item() const
{
    return item;
}

/****************************************************
 * double get_price() const
 *
 * accessor; returns private member price
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: double
****************************************************/
double Souvenir::get_price() const
{
    return price;
}


bool Souvenir::operator==(const Souvenir &s)
{
    if (item == s.item)
        return true;

    return false;
}

