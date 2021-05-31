#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cassert>
#include <QPainter>
#include <sstream>
//using namespace std;


struct Stadiums{
    Stadiums(){}
    Stadiums(std::string sn,std::string tn,std::string ad,std::string csz,std::string bon,std::string d,std::string c,std::string gs,std::string pos){
        Stadium_Name = sn;
        Team_Name = tn;
        address = ad;
        City_State_Zip = csz;
        Box_Office_Num = bon;
        Date_Opened = d;
        std::stringstream ss1(d);
        std::vector<std::string> str;
        std::string stri;
        while(ss1 >> stri)
            str.push_back(stri);
        str.at(3) = str.at(3).substr(0,str.at(3).length()-1);
        month = find_month(str.at(2));
        std::stringstream ss2(str.at(3));
        ss2 >> day;
        std::stringstream ss3(str.at(4));
        ss3 >> year;
        Seating_Capacity = c;
        surface = gs;
        std::stringstream ss(pos);
        std::vector<int> vec;
        int num;
        while(ss >> num)
            vec.push_back(num);
        position.setX(vec[0]);
        position.setY(vec[1]);

    }
    std::string Stadium_Name;
    std::string Team_Name;
    std::string address;
    std::string City_State_Zip;
    std::string Box_Office_Num;
    std::string Date_Opened;
    int month;
    int day;
    int year;
    std::string Seating_Capacity;
    std::string surface;
    QPoint position;

    int find_month(std::string m){
        if(m == "January")
            return 1;
        if(m == "February")
            return 2;
        if(m == "March")
            return 3;
        if(m == "April")
            return 4;
        if(m == "May")
            return 5;
        if(m == "June")
            return 6;
        if(m == "July")
            return 7;
        if(m == "August")
            return 8;
        if(m == "September")
            return 9;
        if(m == "October")
            return 10;
        if(m == "November")
            return 11;
        if(m == "December")
            return 12;
        else
            return 0;
    }
    friend std::ostream& operator<<(std::ostream& os,const Stadiums& s){
        os << s.Stadium_Name << "\n";
        os << s.Team_Name << "\n";
        os << s.address << "\n";
        os << s.City_State_Zip << "\n";
        os << s.Box_Office_Num << "\n";
        os << s.Date_Opened << "\n";
        os << s.Seating_Capacity << "\n";
        os << s.surface << "\n";
        return os;
    }
};

class StringMin{
public:
    bool operator()(Stadiums& s1,Stadiums& s2){
        return s1.Team_Name < s2.Team_Name;
    }
};

class StadiumsNameMin{
public:
    bool operator()(Stadiums& s1,Stadiums& s2){
        return s1.Stadium_Name < s2.Stadium_Name;
    }
};

class DateMin{
public:
    bool operator()(Stadiums & s1,Stadiums& s2){
        if(s1.year < s2.year) return true;
        if(s1.year == s2.year && s1.month < s2.month) return true;
        if(s1.year == s2.year && s1.month == s2.month && s1.day < s2.day) return true;
        return false;
    }
};

template <typename E, typename C>               // element and comparator
class Heap {                           			// heap interface
    public:

    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

        Heap();                                	// default constructor
        Heap(const Heap& source);     			// copy constructor
        Heap& operator=( const Heap& source );  // overloaded assignment operator
        ~Heap();                               	// destructor

        /**************
         ** MUTATORS **
         **************/

        void insert(E value);       			// insert new data
        E remove();              				// remove root data

        /***************
         ** ACCESSORS **
         ***************/

        E peek();								// retrieve but don't remove root data
        int size() const;
        bool is_empty() const;
        void print_preorder(int position = 0);
        bool contains(std::string stadium_name);
        E find_element(std::string name);

    private:									//place any private member functions
        void expand();							//resize the array

    private:									//private member variables
        E* _elements;               // IN/OUT - a dynamic array that holds the data
        int _size;                  // IN/OUT - size of the dynamic array
        int _capacity;              // IN/OUT - capacity of the dynamic array
};

/****************************************************************
 * Heap Class
 *   This class represents a heap object. It manages 3
 *   attributes, a dynamic array that holds data,
 *   size and capacity of the array.
 ***************************************************************/

/****************************************************************
 *
 * CONSTRUCTOR Heap: Class Heap
 *_______________________________________________________________
 * This constructor initializes the attributes.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The attributes have been initialized.
 ***************************************************************/
template <typename E, typename C>
Heap<E,C>::Heap()                                	// default constructor
{
    _elements = new E[3];
    _size = 0;
    _capacity = 3;
}

/****************************************************************
 *
 * CONSTRUCTOR Heap: Class Heap
 *_______________________________________________________________
 * This constructor initializes the attributes.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     source: the source heap will be copied from
 *
 * POST-CONDITIONS
 *     The attributes have been initialized.
 ***************************************************************/
template <typename E, typename C>
Heap<E,C>::Heap(const Heap& source)     			// copy constructor
{
    // insert all elements in source to current heap
    _capacity = source._capacity;
    _elements = new E[_capacity];
    _size = source._size;
    for(int i = 0;i < source.size();i++){
        _elements[i] = source._elements[i];
    }
}

/****************************************************************
 *
 * Operator =: Class Heap
 *_______________________________________________________________
 * This method overloads the assignment operator.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     source: another heap
 *
 * POST-CONDITIONS
 *     The current arrayBT is identical to the given arrayBT.
 ***************************************************************/
template <typename E, typename C>
Heap<E,C>& Heap<E,C>::operator=( const Heap& source )  // overloaded assignment operator
{
    if(&source != this){
        // clear old heap first
        delete []_elements;
        _capacity = source._capacity;
        _size = source._size;
        _elements = new E[_capacity];

        // insert all elements in source to current heap
        for(int i = 0;i < source.size();i++){
            _elements[i] = source._elements[i];
        }
    }
}

/****************************************************************
 *
 * DESTRUCTOR ~Heap: Class Heap
 *_______________________________________________________________
 * This destructor returns the dynmaic memory to the heap.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     All dymaic memories have been released.
 ***************************************************************/
template <typename E, typename C>
Heap<E,C>::~Heap()                               	// destructor
{
    delete []_elements;
}

/****************************************************************
 *
 * Method insert: Class Heap
 *_______________________________________________________________
 * This method will insert a new element with the given
 *     value to the heap. - returns nothing.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     value: value of new element
 *
 * POST-CONDITIONS
 *     A new element has been inserted to the heap.
 ***************************************************************/
template <typename E, typename C>
void Heap<E,C>::insert(E value)     // IN - value for new element
{
    // heap is empty,the value will be root
    if(_size == 0){
        _elements[0] = value;
        _size++;
    }

    // heap is not empty
    else{
        // insert the value to the last spot first
        _elements[_size] = value;
        _size++;
        C comparator;
        int parent;

        // look for the parent position of the new value
        if(_size-1 == 1)
            parent = 0;
        else{
            if(_size-1 % 2 == 0){
                parent = (_size-1-2)/2;
            }
            else{
                parent = (_size-1-1)/2;
            }
        }
        int to_compare = _size-1;

        // rearrange the heap to the right orders
        while(parent >= 0 && comparator.operator()(value,_elements[parent])){
            _elements[to_compare] = _elements[parent];
            _elements[parent] = value;
            to_compare = parent;
            if(parent == 1)
                parent = 0;
            else{
                if(parent % 2 == 0){
                    parent = (parent-2)/2;
                }else{
                    parent = (parent-1)/2;
                }
            }
        }
        if(_size == _capacity)
            expand();
    }
}

/****************************************************************
 *
 * Method remove: Class Heap
 *_______________________________________________________________
 * This method will remove the root and return the value of the root.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *     None.
 *
 * POST-CONDITIONS
 *     The root has been removed and the value of it returned.
 ***************************************************************/
template <typename E, typename C>
E Heap<E,C>::remove()              				// remove root data
{
    assert(_size != 0);

    // remove the root and decrease the size
    E value = _elements[0];
    _elements[0] = _elements[_size-1];
    _elements[_size-1] = value;
    _size--;
    int to_compare = 0,parent = 0;
    int left_child,right_child;
    C comparator;

    // rearrange the heap to the right orders
    if(to_compare*2+2 < _size){
        left_child = to_compare*2+1;
        right_child = to_compare*2+2;
        to_compare = comparator.operator()(_elements[left_child],_elements[right_child]) ? left_child : right_child;
    }
    else{
        // look for the child
        if(to_compare*2+1 < _size)
           to_compare = to_compare*2+1;
    }
    while(comparator.operator()(_elements[to_compare],_elements[parent])){
        value = _elements[parent];

        // swap the child value and the parent value
        _elements[parent] = _elements[to_compare];
        _elements[to_compare] = value;
        parent = to_compare;

        // look for the children if they are any
        if(to_compare*2+2 < _size){
            left_child = to_compare*2+1;
            right_child = to_compare*2+2;
            to_compare = comparator.operator()(_elements[left_child],_elements[right_child]) ? left_child : right_child;
        }
        else{
            if(to_compare*2+1 < _size)
               to_compare = to_compare*2+1;
        }
    }

    // returns the value of the root has been deleted
    return value;
}

/****************************************************************
 *
 * Method peek: Class Heap
 *_______________________________________________________________
 * This method will return the root's value.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The value of the root returned.
 ***************************************************************/
template <typename E, typename C>
E Heap<E,C>::peek()         			// retrieve but don't remove root data
{
    assert(_size != 0);
    return _elements[0];
}

/****************************************************************
 *
 * Method size: Class Heap
 *_______________________________________________________________
 * This method will return the size of the heap.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The size of the heap returned.
 ***************************************************************/
template <typename E, typename C>
int Heap<E,C>::size() const
{
    return _size;
}

/****************************************************************
 *
 * Method is_empty: Class Heap
 *_______________________________________________________________
 * This method will check if the heap is empty or not.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     Returns true if the heap is empty, returns false otherwise.
 ***************************************************************/
template <typename E, typename C>
bool Heap<E,C>::is_empty() const
{
    return _size == 0;
}

/****************************************************************
 *
 * Method expand: Class Heap
 *_______________________________________________________________
 * This method will expand the heap to a new capacity.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The capacity of the heap has been expanded.
 ***************************************************************/
template <typename E, typename C>
void Heap<E,C>::expand()
{
    _capacity*=2;
    E* new_arr = new E[_capacity];
    for(int i = 0;i < _size;i++){
        new_arr[i] = _elements[i];
    }
    delete [] _elements;
    _elements = new_arr;
}

/****************************************************************
 *
 * Method print_preorder: Class Heap
 *_______________________________________________________________
 * This method will print the heap in preorder.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined value:
 *     position: position to start print with.
 *
 * POST-CONDITIONS
 *     Prints the heap in preorder.
 ***************************************************************/
template <typename E, typename C>
void Heap<E,C>::print_preorder(int position)  // IN - position to start with
{
    if(position >= _size)
        return;

    // print root node, left node, then right node
    std::cout << _elements[position] << " ";
    print_preorder(position*2+1);
    print_preorder(position*2+2);
}

template <typename E, typename C>
bool Heap<E,C>::contains(std::string stadium_name)
{
    for(int i = 0;i < _size;i++){
        if(_elements[i].Stadium_Name == stadium_name)
            return true;
    }
    return false;
}

template <typename E, typename C>
E Heap<E,C>::find_element(std::string name)
{
    for(int i = 0;i < _size;i++){
        if(_elements[i].Stadium_Name == name)
            return _elements[i];
    }
}
#endif // HEAP_H
