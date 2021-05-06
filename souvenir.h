#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;


class Souvenir
{
public:
    Souvenir();
    Souvenir(string name, double p, int q);

    // MUTATORS:
    void set_item(string name);
    void set_price(double p);
    void set_quantity(int q);

    // ACCESSORS:
    string get_item() const;
    double get_price() const;
    int get_quantity() const;

    bool operator ==(const Souvenir& s);

private:
    string item;        // IN: souvenir item name
    double price;       // IN: souvenir price
    int quantity;       // IN: quantity of souvenir
};



#endif // SOUVENIR_H
