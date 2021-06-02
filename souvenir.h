#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;


class Souvenir
{
public:
    Souvenir();
    Souvenir(string name, double p);

    // MUTATORS:
    void set_item(string name);
    void set_price(double p);

    // ACCESSORS:
    string get_item() const;
    double get_price() const;

    bool operator ==(const Souvenir& s);

private:
    string item;        // IN: souvenir item name
    double price;       // IN: souvenir price
};
#endif // SOUVENIR_H
