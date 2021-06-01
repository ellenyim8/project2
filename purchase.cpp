#include "purchase.h"

/***********************************************
 * Purchase()
 *  Constructor; initialize an empty purchase
 * --------------------------------------------
 *  Parameters: none
 * --------------------------------------------
 *  Returns: nothing
***********************************************/
Purchase::Purchase()
{
    souvenir_name = "";
    price = 0.0;
    quantity = 0;
}

/***********************************************
 * Purchase()
 *  copy constructor
 * --------------------------------------------
 *  Parameters: purchase pointer object
 * --------------------------------------------
 *  Returns: nothing
***********************************************/
Purchase::Purchase(const Purchase& p)
{
    this->souvenir_name = p.souvenir_name;
    this->price = p.price;
    this->quantity = p.quantity;
}

/***********************************************
 * Purchase()
 *  constructor; initializes private member with
 *  given parameters
 * --------------------------------------------
 *  Parameters: item (IN: string), price (IN: double)
 *  quantity (IN: int)
 * --------------------------------------------
 *  Returns: nothing
***********************************************/
Purchase::Purchase(std::string item,    // IN - souvenir name
                   double price,        // IN - price of souvenir
                   int quantity)        // IN - number of souvenirs bought
{
    this->souvenir_name = item;
    this->price = price;
    this->quantity = quantity;
}

/***********************************************
 * Purchase()
 *  assignment operator
 * --------------------------------------------
 *  Parameters: purchase pointer object
 * --------------------------------------------
 *  Returns: nothing
***********************************************/
Purchase& Purchase::operator=(const Purchase& p)
{
    this->souvenir_name = p.souvenir_name;
    this->price = p.price;
    this->quantity = p.quantity;

    return *this;
}

/***********************************************
 * bool setSouvenirName(string name)
 *  mutator; sets souvenir name
 * --------------------------------------------
 *  Parameters: (IN: string) name
 * --------------------------------------------
 *  Returns: bool
***********************************************/
bool Purchase::setSouvenirName(std::string name)
{
    if (name.length() == 0)
        return false;

    souvenir_name = name;
    return true;
}

/***********************************************
 * bool setPrice(double price)
 *  mutator; sets souvenir price
 * --------------------------------------------
 *  Parameters: (IN: double) price
 * --------------------------------------------
 *  Returns: bool
***********************************************/
bool Purchase::setPrice(double price)
{
    if (price < 0)
        return false;

    this->price = price;
    return true;
}

/***********************************************
 * bool setQuantity(int quantity)
 *  mutator; sets quantity
 * --------------------------------------------
 *  Parameters: (IN: int) quantity
 * --------------------------------------------
 *  Returns: bool
***********************************************/
bool Purchase::setQuantity(int quantity)
{
    if (quantity < 0)
        return false;

    this->quantity = quantity;
    return true;
}

/***********************************************
 * string getSouvenirName() const
 *  accessor; returns souvenir item name
 * --------------------------------------------
 *  Parameters: none
 * --------------------------------------------
 *  Returns: string
***********************************************/
std::string Purchase::getSouvenirName() const
{
    return this->souvenir_name;
}

/***********************************************
 * double getPrice() const
 *  accessor; returns souvenir price
 * --------------------------------------------
 *  Parameters: none
 * --------------------------------------------
 *  Returns: double
***********************************************/
double Purchase::getPrice() const
{
    return this->price;
}

/***********************************************
 * int getQuantity() const
 *  accessor; returns how much bought for souvenir
 * --------------------------------------------
 *  Parameters: none
 * --------------------------------------------
 *  Returns: int
***********************************************/
int Purchase::getQuantity() const
{
    return this->quantity;
}

/***********************************************
 * double getTotalForSouvenir() const
 *  accessor; returns total spent for single
 *  souvenir
 * --------------------------------------------
 *  Parameters: none
 * --------------------------------------------
 *  Returns: double
***********************************************/
double Purchase::getTotalForSouvenir() const
{
    return (this->price * this->quantity);
}

bool Purchase::operator==(const Purchase &p) const
{
    if (p.getSouvenirName() == this->souvenir_name &&
        p.getPrice() == this->price &&
        p.getQuantity() == this->getQuantity())
        return true;

    else
        return false;
}
