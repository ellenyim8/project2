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
    quantity = 0;
}

/****************************************************
 * Souvenir(string n, double p, int q)
 *
 * constructor; sets parameters value with
 * private member variables
 * -------------------------------------------------
 *  Parameters: (string) n, (double) p, (int) q
 * -------------------------------------------------
 *  Returns: none
****************************************************/
Souvenir::Souvenir(string n, double p, int q)
{
    item = n;
    price = p;
    quantity = q;
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
 * void set_quantity(int q)
 *
 * mutator; sets parametized int with private
 * member int quantity
 * -------------------------------------------------
 *  Parameters: q (IN: int)
 * -------------------------------------------------
 *  Returns: none
****************************************************/
void Souvenir::set_quantity(int q)
{
    quantity = q;
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

/****************************************************
 * int get_quantity() const
 *
 * accessor; returns private member quantity
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: string
****************************************************/
int Souvenir::get_quantity() const
{
    return quantity;
}

bool Souvenir::operator==(const Souvenir &s)
{
    if (item == s.item)
        return true;

    return false;
}

