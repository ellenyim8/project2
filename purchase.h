#ifndef PURCHASE_H
#define PURCHASE_H
#include <iostream>
#include <string>
#include <QTextStream>

#include "global.h"
#include "souvenir.h"

class Purchase
{
public:
    /******************
     ** CONSTRUCTORS **
    ******************/
    Purchase();
    Purchase(const Purchase& p);
    Purchase(std::string item,  // IN - souvenir name
             double price,      // IN - price of souvenir
             int quantity);     // IN - # of souvenirs bought

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
    std::string getSouvenirName() const;
    double getPrice() const;
    int getQuantity() const;
    double getTotalForSouvenir() const;
    bool operator ==(const Purchase& p) const;

private:
    std::string souvenir_name;
    double price;
    int quantity;
};

/*
Souvenir s1("Baseball bat", 35.35);
Souvenir s2("Baseball cap", 25.99);
Souvenir s3("Team pennant", 12.99);
Souvenir s4("Autographed baseball", 19.99);

*/

#endif // PURCHASE_H
