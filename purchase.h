#ifndef PURCHASE_H
#define PURCHASE_H
#include <iostream>
#include <string>
#include <QTextStream>

#include "souvenircontainer.h"
#include "souvenir.h"
#include "heap.h"
#include "stadium.h"


class Purchase
{
public:
    /******************
     ** CONSTRUCTORS **
    ******************/
    Purchase();
    Purchase(const Purchase& p);
    Purchase(string, double, int);

    /***************
     ** MUTATORS **
    ***************/
    Purchase& operator =(const Purchase& p);
    bool setSouvenirName(std::string name);
    bool setPrice(double price);
    bool setQuantity(int quantity);

    /***************
     ** ACCESSORS **
    ***************/
    std::string getSouvenir() const;
    double getPrice() const;
    int getQuantity() const;
    double getTotalCost() const;        // get total cost for purchase of souvenir
    bool operator ==(const Purchase& p);
//    string get_souvenir_name(string sv) const;
//    int get_souvenir_price(string sv) const;
//    double get_total(string sv) const;

private:
    std::string souvenir_name;
    double _price;
    int _quantity;          // how many souvenir is purchased

};

#endif // PURCHASE_H
