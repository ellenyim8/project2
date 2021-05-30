#include "purchase.h"

Purchase::Purchase()
{
    souvenir_name = "";
    price = 0.0;
    quantity = 0;
}

Purchase::Purchase(const Purchase& p)
{
    this->souvenir_name = p.souvenir_name;
    this->price = p.price;
    this->quantity = p.quantity;
}

Purchase::Purchase(std::string item,    // IN - souvenir name
                   double price,        // IN - price of souvenir
                   int quantity)        // IN - number of souvenirs bought
{
    this->souvenir_name = item;
    this->price = price;
    this->quantity = quantity;
}

Purchase& Purchase::operator=(const Purchase& p)
{
    this->souvenir_name = p.souvenir_name;
    this->price = p.price;
    this->quantity = p.quantity;

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

    this->price = price;
    return true;
}

bool Purchase::setQuantity(int quantity)
{
    if (quantity < 0)
        return false;

    this->quantity = quantity;
    return true;
}


std::string Purchase::getSouvenirName() const
{
    return this->souvenir_name;
}

double Purchase::getPrice() const
{
    return this->price;
}

int Purchase::getQuantity() const
{
    return this->quantity;
}

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
