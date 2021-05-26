#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

/************************************************************
*
* node struct
*   This is a node struct that stores data and links both way
*
*************************************************************/
template <class T>
struct node
{
    T data;         // data stored
    node* next;     // link to the next node
    node* last;     // link to prev node
};

template <class T>
class lists
{
  public:
    // constructor/destructor
    lists();
    lists(const lists& l);
    ~lists();

    // list modifier
    void push_back(T data);
    void push_front(T data);
    void pop();
    void pop_front();
    void remove(T data);

    // list content accessor
    int size();
    T at(int index);
    bool empty();
    bool find(T data);
    T first();
    T last();

    // sorting functions
    void insert_sorted(T data);

private:
    node<T>* _root;     // first element of the list
    node<T>* _last;     // last element of the list
    int _size;          // current size of the list
};

/************************************************************
*
* list class
*   This is templated double linked list class
*
*************************************************************/

/******************************
** CONSTRUCTOR & DESTRUCTOR **
******************************/

/************************************************************
*
* list class constructor
*___________________________________________________________
* This is the default constructor for list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
lists<T>::lists()
{
    // initialize all fields
    _size = 0;
    _root = nullptr;
    _last = nullptr;
}

/************************************************************
*
* list class copy constructor
*___________________________________________________________
* This is the copy constructor for list
*___________________________________________________________
* INPUTS:
*   const list& l   -   given list to copy from
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
lists<T>::lists(const lists& l)
{
    _size = l._size;

    // a walker for both list
    node<T>* this_temp;
    node<T>* l_temp = l._root;

    // copy the root
    if(l_temp)
    {
        _root = new node<T>;
        _root->data = (l._root)->data;
        l_temp = l_temp->next;
        this_temp = _root;
    }

    // copy the rest and last/next
    while(l_temp)
    {
        this_temp->next = new node<T>;
        (this_temp->next)->last = this_temp;
        this_temp = this_temp->next;
        this_temp->data = l_temp->data;
        l_temp = l_temp->next;
    }

    _last = this_temp;
}

/************************************************************
*
* list class destructor
*___________________________________________________________
* This is the destructor for list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
lists<T>::~lists()
{

}

/************************************************************
*
* push_back(T data)
*___________________________________________________________
* This is the push back function for list that insert a
*   node at the end of the list
*___________________________________________________________
* INPUTS:
*   T data      -    data to insert
*
* OUTPUTS:
*   None
*
*************************************************************/
template<class T>
void lists<T>::push_back(T data)
{
    // create a node to add
    node<T>* to_add = new node<T>();
    to_add->data = data;
    to_add->last = _last;

    // check where to add
    if(_last)
        _last->next = to_add;
    else
        _root = to_add;
    _last = to_add;
    _last->next = nullptr;
    _size ++;
}

/************************************************************
*
* push_front(T data)
*___________________________________________________________
* This is the push front function for list that insert a
*   node at the front of the list
*___________________________________________________________
* INPUTS:
*   T data      -    data to insert
*
* OUTPUTS:
*   None
*
*************************************************************/
template<class T>
void lists<T>::push_front(T data)
{
    // create a node to add
    node<T>* to_add = new node<T>();
    to_add->data = data;
    to_add->next = _root;

    // check where to add
    if(_root)
        _root->last = to_add;
    else
        _last = to_add;
    _root = to_add;
    _size ++;
}

/************************************************************
*
* pop()
*___________________________________________________________
* This is the pop function for list that pops the last node
*   of the list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/
template<class T>
void lists<T>::pop()
{
    if(!empty())
    {
        // find last node and remove it
        node<T>* temp = _last;
        _last = _last->last;
        delete temp;
        _size--;
        if(_last == nullptr)
            _root = nullptr;
    }
}

/************************************************************
*
* pop_front()
*___________________________________________________________
* This is the pop function for list that pops the first node
*   of the list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
void lists<T>::pop_front()
{
    if(!empty())
    {
        // delete the first node
        node<T>* temp = _root;
        _root = _root->next;
        delete temp;
        _size--;
        if(_root == nullptr)
            _last = nullptr;
    }
}

/************************************************************
*
* remove(T data)
*___________________________________________________________
* This is the remove function for list that removes a given
*   data from the list
*___________________________________________________________
* INPUTS:
*   T data  -   given data to remove
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
void lists<T>::remove(T data)
{
    assert(!empty());

    // find the give ndata
    node<T>* temp = _root;
    while(temp && !(temp->data == data))
        temp = temp->next;

    if(temp)
    {
        // remove it accordingly
        if(temp ==_root)
            pop_front();
        else if(temp == _last)
            pop();
        else
        {
            (temp->last)->next = temp->next;
            (temp->next)->last = temp->last;
            delete temp;
            _size--;
        }
    }
}

/************************************************************
*
* size()
*___________________________________________________________
* This is the size functio that access the size of list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   returns the size of current list
*
*************************************************************/
template <class T>
int lists<T>::size()
{
    return _size;
}

/************************************************************
*
* at(int index)
*___________________________________________________________
* This is the at functio that access the content at given
*   index
*___________________________________________________________
* INPUTS:
*   int index   -   given index to access
*
* OUTPUTS:
*   returns the value at given index position
*
*************************************************************/
template <class T>
T lists<T>::at(int index)
{
    assert(index < _size);

    node<T>* walker = _root;
    for(int i=0; i<index; i++)
        walker = walker->next;

    return walker->data;
}

/************************************************************
*
* at(int index)
*___________________________________________________________
* This is the empty functio checks if list is empty
*   index
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   returns the true if list is empty, false otherwise
*
*************************************************************/
template <class T>
bool lists<T>::empty()
{
    return _size == 0;
}

/************************************************************
*
* find(T data)
*___________________________________________________________
* This is the finc functio nthat checks if given data
*   exists in the list
*___________________________________________________________
* INPUTS:
*   T data  -   give ndata to fnd
*
* OUTPUTS:
*   returns the true if data is in the list, false otherwise
*
*************************************************************/
template <class T>
bool lists<T>::find(T data)
{
    for(int i=0; i<_size; i++)
        if(at(i) == data)
            return true;
    return false;
}

/************************************************************
*
* insert_sorted(T data)
*___________________________________________________________
* This is the insert sort function that sorts the give ndata
*   into the list
*___________________________________________________________
* INPUTS:
*   T data  -   give ndata to insert
*
* OUTPUTS:
*   None
*
*************************************************************/
template <class T>
void lists<T>::insert_sorted(T data)
{
    // if list is empty
    if(empty())
        push_back(data);
    else
    {
        // check if needed to insert front or back
        if(data > _last->data)
            push_back(data);
        else if(data < _root->data)
            push_front(data);
        else
        {
            // go thru the list and find right position to insert
            node<T>* walker = _root;
            for(int i=0; i<_size; i++)
            {
                if(data > walker->data && data < (walker->next)->data)
                {
                    node<T>* to_add = new node<T>;
                    to_add->data = data;

                    to_add->next = walker->next;
                    to_add->last = walker;
                    (walker->next)->last = to_add;
                    walker->next = to_add;
                    _size ++;
                    break;
                }
                walker = walker->next;
            }
        }
    }

}

/************************************************************
*
* first()
*___________________________________________________________
* This is the access fucntion that gets the value locates
*   that the first item in the list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   Returns the first item in the list
*
*************************************************************/
template <class T>
T lists<T>::first()
{
    if(!empty())
        return at(0);
    else
    {
        cout << "list is empty" << endl;
        return T();
    }
}

/************************************************************
*
* last()
*___________________________________________________________
* This is the access fucntion that gets the value locates
*   that the last item in the list
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   Returns the last item in the list
*
*************************************************************/
template <class T>
T lists<T>::last()
{
    if(!empty())
        return at(_size-1);
    else
    {
        cout << "list is empty" << endl;
        return T();
    }
}





#endif // LIST_H
