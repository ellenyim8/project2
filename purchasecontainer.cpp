#include "purchasecontainer.h"

/****************************************************
 * PurchaseContainer()
 *  CTOR; initializes ctor private members to 0
 *  Preconditions: none
 *  Postcondition: initializes to 0
*****************************************************/
PurchaseContainer::PurchaseContainer()
{
    list = 0;
    _size = 0;
    _capacity = 0;
}

PurchaseContainer::PurchaseContainer(int size)
{
    _capacity = size;
    _size = size;
    list = new Purchase[size];
}

PurchaseContainer::PurchaseContainer(int size, const Purchase& initial)
{
    _size = size;
    _capacity = size;
    list = new Purchase[size];
    for (int i=0; i<size; i++)
    {
        list[i] = initial;
    }
}

PurchaseContainer::PurchaseContainer(const PurchaseContainer& pc)
{
    _size = pc._size;
    _capacity = pc._capacity;
    list = new Purchase[_size];
    for (int i=0; i<_size; i++)
    {
        list[i] = pc.list[i];
    }
}

PurchaseContainer::~PurchaseContainer()
{
    delete[] list;
}

/****************************************************
 * int capacity() const
 *  Accessor; This method returns the allocated size
 *  of the container
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: int
*****************************************************/
int PurchaseContainer::capacity() const
{
    return _capacity;
}

/****************************************************
 * int size() const
 *  Accessor; This method returns the size of the
 * container
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: int
*****************************************************/
int PurchaseContainer::size() const
{
    return _size;
}

/****************************************************
 * bool empty() const
 *  Accessor; This method returns if the container is
 *  empty or not
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: bool
*****************************************************/
bool PurchaseContainer::empty() const
{
    return (_capacity == 0);
}

/****************************************************
 * Purchase& operator[](int index) const
 *  Accessor; returns the purchase found at index
 *  passed by the parameter
 * --------------------------------------------------
 *  Parameters: int (IN: index)
 * --------------------------------------------------
 *  Returns: purchase object at parameter index
*****************************************************/
Purchase& PurchaseContainer::operator[](int index) const
{
    assert(index < _size);
    return list[index];
}

/****************************************************
 * double getTotal() const
 *  Accessor; gets the total cost for a purchase
 *  object
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: double
*****************************************************/
double PurchaseContainer::getTotal() const
{
    if (_size == 0)
        return 0.0;

    double total;
    total = 0.0;
    for (int i=0; i<_size; i++)
    {
        total += list[i].getTotalForSouvenir();
    }

    return total;
}

/****************************************************
 * int find(const Purchase& p) const
 *  Accessor; finds the purchase object within private
 *  member _size
 * --------------------------------------------------
 *  Parameters: const Purchase object
 * --------------------------------------------------
 *  Returns: int (-1 if purchase object is not found)
*****************************************************/
int PurchaseContainer::find(const Purchase &p) const
{
    for (int i=0; i<_size; i++)
    {
        if (list[i] == p)
            return i;
    }

    return -1;  // if purchase object is not found
}

/****************************************************
 * int find(string name) const
 *  Accessor; finds the souvenir index in
 *  PurchaseContainer size
 * --------------------------------------------------
 *  Parameters: (string) name
 * --------------------------------------------------
 *  Returns: int (-1 if purchase object is not found)
*****************************************************/
int PurchaseContainer::find(std::string name) const
{
    for (int i=0; i<_size; i++)
    {
        if (list[i].getSouvenirName() == name)
            return i;
    }

    return -1;  // if string name is not found in list
}

/****************************************************
 * int getSouvenirQuantity(string name) const
 * Accessor;
 * --------------------------------------------------
 *  Parameters: (string) name
 * --------------------------------------------------
 *  Returns: (int) how much of a souvenir is purchased
*****************************************************/
int PurchaseContainer::getSouvenirQuantity(std::string name) const
{
    int count;
    count = 0;

    for (int i=0; i<_size; i++)
    {
        if (name == list[i].getSouvenirName())
            count += list[i].getQuantity();
    }

    return count;
}

/****************************************************
 * int find(const Purchase& p) const
 *  Accessor; finds the purchase object within private
 *  member _size
 * --------------------------------------------------
 *  Parameters: const Purchase object
 * --------------------------------------------------
 *  Returns: (bool) (true if purchase object is found)
 *  (false if it's not found)
*****************************************************/
bool PurchaseContainer::contains(Purchase &p) const
{
    for (int i=0; i<_size; i++)
    {
        if (list[i] == p)
            return true;
    }

    return false;
}

/****************************************************
 * void push_back(const Purchase& p)
 *  Mutator; adds the parameterized purchase object
 *  to container
 * --------------------------------------------------
 *  Parameters: const Purchase object
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::push_back(const Purchase &p)
{
    if (this->size() >= this->capacity())
        reserve(this->capacity() + 5);

    list[_size++] = p;
}

void PurchaseContainer::push_back(QWidget *parent,  // IN: point errors to
                                  const Purchase &p,    // IN: purchase to add to container
                                  SouvenirContainer &sc)    // IN: container of all souvenirs
{
    if (p.getQuantity() > 100)
    {
        QMessageBox::warning(parent, "Warning", "Purchase exceeds 100.");
        return;
    }

    if (!sc.contains(p.getSouvenirName()))
    {
        QString name = p.getSouvenirName().c_str();
        QMessageBox::warning(parent, "Warning", "Souvenir " + name + " does not exist. ");
        return;
    }

    if (_size > _capacity)
        reserve(_capacity + 5);

    list[_size++] = p;
}

/****************************************************
 * void pop_back()
 *  Mutator; removes the last purchase
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::pop_back()
{
    _size--;
}

/****************************************************
 * void remove(const Purchase& p)
 *  Mutator; removes the given purchase object
 * --------------------------------------------------
 *  Parameters: const Purchase object
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::remove(const Purchase &p)
{
    int index;
    index = find(p);

    if (index == -1)
        return;

    for (int i=index; i<_size - 1; i++) {
        list[i] = list[i+1];
    }

    _size--;
}

/****************************************************
 * void set_size(int size)
 *  Mutator; sets a new size for container
 * --------------------------------------------------
 *  Parameters: (int) size
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::set_size(int size)
{
    _size = size;
}

/****************************************************
 * void set_capacity(int cap)
 *  Mutator; sets a new capacity for container
 * --------------------------------------------------
 *  Parameters: (int) cap
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::set_capacity(int cap)
{
    _capacity = cap;
}

PurchaseContainer& PurchaseContainer::operator=(const PurchaseContainer &p)
{
    if (this != &p)
    {
        this->_size = p._size;
        this->_capacity = p._capacity;
        this->list = new Purchase[this->_size];
        for (unsigned int i=0; i<this->_size; i++)
        {
            this->list[i] = p.list[i];
        }
    }
    return *this;
}

/****************************************************
 * void reserve(unsigned int cap)
 *  Mutator; reallocates a new capacity for container
 * --------------------------------------------------
 *  Parameters: (int) cap
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::reserve(int cap)
{
    if (list == 0) {
        _size = 0;
        _capacity = 1;
    }

    Purchase* new_list = new Purchase[cap];
    assert(new_list);
    copy(list, list + _size, new_list);
    _capacity = cap;
    delete[] list;
    list = new_list;
}

/****************************************************
 * void resize(unsigned int size)
 *  Mutator; sets a new size for container
 * --------------------------------------------------
 *  Parameters: (int) size
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::resize(int size)
{
    reserve(size);
    _size = size;
}

/****************************************************
 * void clear()
 *  Mutator; clears the PurchaseContainer
 * --------------------------------------------------
 *  Parameters: none
 * --------------------------------------------------
 *  Returns: nothing
*****************************************************/
void PurchaseContainer::clear()
{
    delete[] list;

    list = nullptr;
    _size = 0;
}

void PurchaseContainer::readFile(std::string name)
{
    ifstream in(name);
    if (!in.is_open())
        return;

    std::string input;
    while (getline(in, input))
    {
        double price;
        in >> price;        // IN: amount of souvenir
        in.ignore();

        int quantity;
        in >> quantity;     // IN: how many to buy
        in.ignore();

        Purchase temp(input, price, quantity);
        this->push_back(temp);
    }

    in.close();
}

bool PurchaseContainer::readFile(QWidget *parent,
                                 std::string input,
                                 SouvenirContainer &sc)
{
    ifstream in(input);
    if (!in.is_open())
        return false;

    std::string name;
    while (getline(in, name))
    {
        double price;
        in >> price;
        in.ignore();

        int quantity;
        in >> quantity;
        in.ignore();

        Purchase temp(name, price, quantity);
        this->push_back(parent, temp, sc);
    }

    in.close();
    return true;
}

void PurchaseContainer::outFile(std::string name)
{
    ofstream out(name);
    for (int i=0; i<this->size(); i++)
    {
        Purchase temp = (*this)[i];
        out << temp.getSouvenirName() << "\n";
        out << temp.getPrice() << " " << temp.getQuantity() << "\n";
    }
}

