#include "purchase.h"

/***********************************************
 * Purchase()
 *  CTOR; default ctor, initialize class
 *  attributes
 *  Parameters: none
 *  Returns: none
***********************************************/
Purchase::Purchase()
{
    souvenir_name = "";
    _price = 0.0;
    _quantity = 0;
}

Purchase::Purchase(const Purchase& p)
{
    this->souvenir_name = p.souvenir_name;
    this->_price = p._price;
    this->_quantity = p._quantity;
}

Purchase::Purchase(std::string name, double price, int quantity)
{
    souvenir_name = name;
    this->_price = price;
    this->_quantity = quantity;
}

Purchase& Purchase::operator=(const Purchase &p)
{
    if (this != &p)
    {
        this->souvenir_name = p.souvenir_name;
        this->_price = p._price;
        this->_quantity = p._quantity;
    }

    return *this;
}

bool Purchase::setSouvenirName(std::string name)
{
    if (name.length() == 0)
        return false;

    souvenir_name = name;
    return true;
}

bool Purchase::setPrice(double price)
{
    if (price < 0)
        return false;

    this->_price = price;
    return true;
}

bool Purchase::setQuantity(int quantity)
{
    if (_quantity < 0)
        return false;

    _quantity = quantity;
    return true;
}

std::string Purchase::getSouvenir() const
{
    return souvenir_name;
}

double Purchase::getPrice() const
{
    return _price;
}

int Purchase::getQuantity() const
{
    return _quantity;
}

double Purchase::getTotalCost() const
{
    double total;
    total = _price * _quantity;
    return total;
}

bool Purchase::operator==(const Purchase &p)
{
    if (p.getSouvenir() == this->souvenir_name &&
            p.getPrice() == this->_price &&
            p.getQuantity() == this->_quantity)
        return true;

    return false;
}

