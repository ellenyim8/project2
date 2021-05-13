#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <class T>
class Dijkstra{
public:
    typedef pair<T,T> p;
    typedef pair<p,int> p2;

    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    Dijkstra();
    ~Dijkstra();

    /**************
     ** MUTATORS **
     **************/

    void shortest_path();
    void insert_path(p2 path);
    void insert_positions(const T& entry);
    void set_start_position(const T& start){start_position = start;}

    /***************
     ** ACCESSORS **
     ***************/

    int get_size(){return _size;}
    pair<T,int>* get_positions() const;
    vector<vector<T>> get_lists() const;
    void print_positions();
    bool check_positions(const T& value) const;

private:
    T start_position;           // IN/OUT - start position
    pair<T,int>* positions;     // IN/OUT - store the cities and the distances to the cities
    p* Predecessor;             // IN/OUT - store the predecessor
    vector<vector<T>> _lists;   // IN/OUT - store the paths
    vector<p2> _paths;          // IN/OUT - store the paths
    int _size;                  // IN/OUT - size of the positions
    int _capacity;              // IN/OUT - capacity of the positions
    void set_lists();
    int get_position(T value);
};

/****************************************************************
 * Dijkstra Class
 *   This class represents a dijkstra object. It manages 7
 *   attributes.
 ***************************************************************/

/****************************************************************
 *
 * CONSTRUCTOR Dijkstra: Class Dijkstra
 *_______________________________________________________________
 * This constructor initializes the attributes.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The attributes have been initialized.
 ***************************************************************/
template <class T>
Dijkstra<T>::Dijkstra()
{
    _capacity = 100;
    _size = 0;
    Predecessor = new p[_capacity];
    positions = new pair<T,int>[_capacity];
    positions[0].second = 0;
}

/****************************************************************
 *
 * DESTRUCTOR ~Dijkstra: Class Dijkstra
 *_______________________________________________________________
 * This destructor returns the dynmaic memory to the heap.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     All dymaic memories have been released.
 ***************************************************************/
template <class T>
Dijkstra<T>::~Dijkstra()
{
    delete [] Predecessor;
    delete [] positions;
}

/****************************************************************
 *
 * Method shortest_path: Class Dijkstra
 *_______________________________________________________________
 * This method will look for the shortest path from the start
 *   position to each city. - returns nothing.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The shortest paths from the start position to every single
 *       city have been stored in v.
 ***************************************************************/
template <class T>
void Dijkstra<T>::shortest_path()
{
    vector<p2> v;
    for(int i = 0;i < _size;i++){
        for(int j = 0;j < _paths.size();j++){
            if(_paths[j].first.first == positions[i].first || _paths[j].first.second == positions[i].first)
                v.push_back(_paths[j]);
        }
        for(int k = 0;k < v.size();k++){
            int pos = get_position(v.at(k).first.second);
            int pos2 = get_position(v.at(k).first.first);
            if(positions[pos].second > positions[pos2].second + v.at(k).second){
                positions[pos].second = positions[pos2].second + v.at(k).second;
                Predecessor[pos] = v.at(k).first;
            }
        }
    }
    set_lists();
}

/****************************************************************
 *
 * Method check_positions: Class Dijkstra
 *_______________________________________________________________
 * This method will check if the entry is whether in positions.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     value: value to check for
 *
 * POST-CONDITIONS
 *     Returns true if value is in positions, returns false
 *       otherwise.
 ***************************************************************/
template <class T>
bool Dijkstra<T>::check_positions(const T& value)   // IN - value to check for
const
{
    for(int i = 0;i < _size;i++){
        if(positions[i].first == value)
            return true;
    }
    return false;
}

/****************************************************************
 *
 * Method insert_path: Class Dijkstra
 *_______________________________________________________________
 * This method will insert a new element with the given
 *     value to the _paths. - returns nothing.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     path: new element
 *
 * POST-CONDITIONS
 *     A new element has been inserted to the _paths.
 ***************************************************************/
template <class T>
void Dijkstra<T>::insert_path(p2 path)  // IN - new element
{
    _paths.push_back(path);
    insert_positions(path.first.first);
    insert_positions(path.first.second);
}

/****************************************************************
 *
 * Method insert_positions: Class Dijkstra
 *_______________________________________________________________
 * This method will insert a new element with the given
 *     value to the positions. - returns nothing.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     entry: value of new element
 *
 * POST-CONDITIONS
 *     A new element has been inserted to the positions.
 ***************************************************************/
template <class T>
void Dijkstra<T>::insert_positions(const T& entry)  // IN - new element
{
    if(!check_positions(entry)){
        positions[_size].first = entry;
        positions[_size].second = _size == 0 ? 0 : 99999;
        _size++;
    }
}

/****************************************************************
 *
 * Method get_position: Class Dijkstra
 *_______________________________________________________________
 * This method will return the position of the element in the
 *   positions with the given value.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     value: value of the desire element
 *
 * POST-CONDITIONS
 *     Returns the position of the element with the given value.
 ***************************************************************/
template <class T>
int Dijkstra<T>::get_position(T value)
{
    for(int i = 0;i < _size;i++){
        if(positions[i].first == value)
            return i;
    }
}

/****************************************************************
 *
 * Method set_lists: Class Dijkstra
 *_______________________________________________________________
 * This method will set the _lists with the paths from the start
 *   position to other positions.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     The _lists has been set.
 ***************************************************************/
template <class T>
void Dijkstra<T>::set_lists()
{
    vector<T> v;
    v.push_back(start_position);
    _lists.push_back(v);
    for(int i = 1;i < _size;i++){
        v.clear();
        p value = Predecessor[i];
        v.push_back(Predecessor[i].second);
        v.push_back(Predecessor[i].first);
        while(value.first != start_position){
            for(int j = 0;j < _size;j++){
                if(Predecessor[j].second == value.first){
                    v.push_back(Predecessor[j].first);
                    value = Predecessor[j];
                }
            }
        }
        _lists.push_back(v);
    }
}

/****************************************************************
 *
 * Method print_positions: Class Dijkstra
 *_______________________________________________________________
 * This method will print the outputs.
 *_______________________________________________________________
 * PRE-CONDITIONS
 *   None.
 *
 * POST-CONDITIONS
 *     Displays the outputs.
 ***************************************************************/
template <class T>
void Dijkstra<T>::print_positions()
{
    for(int i = 0;i < _size;i++){
        cout << positions[i].first << ":" << positions[i].second;
        cout << "{";
        int k;
        for(k = _lists.at(i).size()-1;k >0;k--)
            cout << _lists[i].at(k) << ",";
        cout << _lists[i].at(k) << "}" << _lists.at(i).size() << endl << endl;
    }
}

template <class T>
pair<T,int>* Dijkstra<T>::get_positions() const
{
    return positions;
}

template <class T>
vector<vector<T>> Dijkstra<T>::get_lists() const
{
    return _lists;
}

#endif // DIJKSTRA_H
