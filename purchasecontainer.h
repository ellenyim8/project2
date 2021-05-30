#ifndef PURCHASECONTAINER_H
#define PURCHASECONTAINER_H
#include "purchase.h"
#include "souvenircontainer.h"
#include "global.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <fstream>


class PurchaseContainer
{
public:
    /******************
     ** CONSTRUCTORS **
    ******************/
    PurchaseContainer();
    PurchaseContainer(int size);
    PurchaseContainer(int size,
                      const Purchase& initial);
    PurchaseContainer(const PurchaseContainer& pc);
    ~PurchaseContainer();

    /***************
     ** ACCESSORS **
    ***************/
    int capacity() const;
    int size() const;
    bool empty() const;
    Purchase& operator[](int index) const;

    double getTotal() const;
    int find(const Purchase& p) const;  // purchase to search for
    int find(std::string name) const;   // purchase to search for
    int getSouvenirQuantity(std::string name) const;
    bool contains(Purchase& p) const;
    Purchase* begin() const {return &list[0];}
    Purchase* end() const {return &list[_size];}

    /***************
     ** MUTATORS **
    ***************/
    void push_back(const Purchase& p);
    void push_back(QWidget* parent,
                   const Purchase& p,
                   SouvenirContainer& sc);
    void pop_back();
    void remove(const Purchase& p);

    void set_size(int size);
    void set_capacity(int cap);
    PurchaseContainer& operator =(const PurchaseContainer& p);

    void reserve(int cap);
    void resize(int size);
    void clear();

    bool readFile(QWidget* parent,
                  std::string input,
                  SouvenirContainer& sc);
    void readFile(std::string name);
    void outFile(std::string name);

private:
    int _size;              // IN- allocated size of container
    int _capacity;          // IN- size of container
    Purchase *list;         // IN- array of purchases

};


/*********************************************************************
 * PurchaseContainer class
 *      This class represents a container of purchase objects. It handles
 *      3 attributes: _size of container, allocated _capacity of container
 *      array of purchases.
*********************************************************************/


#endif // PURCHASECONTAINER_H
