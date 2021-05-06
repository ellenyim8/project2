#ifndef SOUVENIRCONTAINER_H
#define SOUVENIRCONTAINER_H
#include "souvenir.h"
#include <fstream>
#include <ostream>
#include <cassert>

class SouvenirContainer
{
public:
    // CONSTRUCTORS & DESTRUCTOR
    SouvenirContainer();
    ~SouvenirContainer();

    // ACCESSORS
    bool contains(const string& item);
    int get_souvenirs_count() {return souvenir_count;}
    Souvenir& operator[](int index) const {return souvenirs[index];}
    Souvenir get_souvenir(int i) {return souvenirs[i];}
    Souvenir* begin() {return &souvenirs[0];}
    Souvenir* end() {return &souvenirs[souvenir_count];}

    Souvenir get_souvenir(string name)
    {
        assert(this->contains(name));
        for (int i=0; i<souvenir_count; i++) {
            if (souvenirs[i].get_item() == name)
                return souvenirs[i];
        }
        return souvenirs[0];
    }

    int get_souvenir_index(string name) {
        for (int i=0; i<souvenir_count; i++) {
            if (souvenirs[i].get_item() == name)
                return i;
        }
        return -1;
    }

    // MUTATORS
    void add_souvenir(const Souvenir& new_souvenir);
    void remove_souvenir(const string& item);


    void readFile(string name);
    void outFile(string name);

private:
    Souvenir* souvenirs;    // IN: array of souvenirs
    int souvenir_count;     // size of souvenir container
};


/***************************************************
 * this class
 *
 *
 * // CONSTRUCTORS & DESTRUCTOR
 *  SouvenirContainer();
 *  SouvenirContainer(int size);
 *  SouvenirContainer(int size, const Souvenir& s);
 *  SouvenirContainer(const SouvenirContainer& rhs)
 *  ~SouvenirContainer()
 *
 * // ACCESSORS
 *  int capacity() const;
 *  int size() const;
 *  bool empty() const;
 *  bool contains(string souvenir) const;
 *  int search(const Souvenir& s) const;
 *  int search(string name);
 *  Souvenir& operator[](int index) const;
 *  Souvenir* begin() {return &souvenirs[0];}
 *  Souvenir* end() {return &souvenirs[_size];}
 *  string getSouvenirName() const {return souvenirs->get_item();}
 *  double getSouvenirPrice() const {return souvenirs->get_price();}
 *  int getSouvenirQuantity() const {return souvenirs->get_quantity();}
 *
 * // MUTATORS
 *  void push_back(const Souvenir& s);
 *  void pop_back();
 *  void remove(const Souvenir& s);
 *  void reallocate(int cap);
 *  void resize(int size);
 *  void clear();
 *  void set_size(int size);
 *  void set_capacity(int cap);
 *
 *  SouvenirContainer& operator+=(const Souvenir& s);
 *  SouvenirContainer& operator=(const SouvenirContainer& rhs);
 *
 *
****************************************************/

#endif // SOUVENIRCONTAINER_H
