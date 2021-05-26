#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include "list.h"
using namespace std;
/************************************************************
*
* city struct
*   This is a city struct that stores name of the city and
*   weight from last city to the current one
*
*************************************************************/
struct city
{
    // constructor
    city():name(""), weight(0){}
    city(string str, int num):name(str), weight(num){}

    string name;    // name if the city
    int weight;     // distance from last one to current

    // comparison operator overload
    friend bool operator==(city c1, city c2)
    {
        return c1.name == c2.name;
    }

    // extraction operator overload
    friend ostream& operator<<(ostream& os, city c)
    {
        os <<  c.name.data();
        return os;
    }
};

/************************************************************
*
* edge struct
*   This is a edge struct that stores two city and their
*   distance
*
*************************************************************/
struct edge
{
    // constructor
    edge(){}
    edge(string str1, string str2, int n)
        :city_1(str1), city_2(str2), weight(n){}

    string city_1;  // first city
    string city_2;  // second city
    int weight;     // distance between two city

    // comparison operator overload
    friend bool operator<(edge c1, edge c2)
    {
        return c1.weight < c2.weight;
    }
    friend bool operator>(edge c1, edge c2)
    {
        return c1.weight > c2.weight;
    }
    friend bool operator==(edge c1, edge c2)
    {
        return c1.weight == c2.weight && c1.city_1 == c2.city_1
                && c1.city_2 == c2.city_2;
    }

    // extraction operator overload
    friend ostream& operator<<(ostream& os, edge e)
    {
        os << "(" << e.city_1.data() << ", " << e.city_2.data() << ")";
        os << " " << e.weight;
        return os;
    }
};

class graph
{
public:
    // constructor
    graph();

    // typical graph functions
    bool isEmpty();
    lists<city> incidentEdges(string city);
    int search_edge(lists<edge> l, string city);
    bool isCycle(lists<edge> l, edge e);

    // city information
    int indexOf(string c);
    int cost_of(string c1, string c2);

    // Graph alorithm
    void print_path(int arr[], int size, int index,vector<string>& vec);
    void Dijstra(string start,vector<pair<int,vector<string>>>& vec);
    void MST_Prim(string start);
    void MST_Kruskal();

    // Graph construction
    void construct_graph();

private:
    lists<city> adj_list[30];    // list to store the graph
    int size;                   // number of cities
};

/************************************************************
*
* Graph class
*   This is a graph class that stores graph and find MST and
*   shortest path
*
*************************************************************/


/************************************************************
*
* graph()
*___________________________________________________________
* This is the default constructor for graph
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/

/************************************************************
*
* isEmpty()
*___________________________________________________________
* This function checkis if graph is empty or not
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   bool    -   true if empty, false otherwise
*
*************************************************************/

/************************************************************
*
* incidentEdges(string city)
*___________________________________________________________
* This function finds all the incident edges to a city
*___________________________________________________________
* INPUTS:
*   string city -   given city to find incident edges for
*
* OUTPUTS:
*   returns a list of incident edges to the give city
*
*************************************************************/

/************************************************************
*
* search_edge(list<edge> l, string city)
*___________________________________________________________
* This function finds all the edge associate with the given
*   city
*___________________________________________________________
* INPUTS:
*   string city -   given city to find its edge
*
* OUTPUTS:
*   returns the index of given city's all edge
*
*************************************************************/

/************************************************************
*
* isCycle(list<edge> l, edge e)
*___________________________________________________________
* This function checks will given edge is added to the given
*   list edge creates a loop/cycle
*___________________________________________________________
* INPUTS:
*   list<edge> l    -   give list of edge to check for loop
*   edge e          -   given edge to check for cycle after
*                           added to the list
*
* OUTPUTS:
*   returns true if it will create a loop, false otherwise
*
*************************************************************/

/************************************************************
*
* indexOf(string c)
*___________________________________________________________
* This function find the index of given city in the graph
*   list
*___________________________________________________________
* INPUTS:
*   string c    -   give ncity to find
*
* OUTPUTS:
*   returns the index of given city in the list
*
*************************************************************/

/************************************************************
*
* cost_of(string c1, string c2)
*___________________________________________________________
* This function finds the cost of going from given city 1
*   to city 2
*___________________________________________________________
* INPUTS:
*   string c1    -   given first city to find
*   string c2    -   given second city to find
*
* OUTPUTS:
*   returns the weight between two given cities
*
*************************************************************/

/************************************************************
*
* print_path(int arr[], int size, int index)
*___________________________________________________________
* This recursive function prints a given arr of path
*___________________________________________________________
* INPUTS:
*   int arr[]   -   given array of path to print
*   int size    -   given array's size
*   int index   -   current index of path to print
*
* OUTPUTS:
*   None
*
*************************************************************/

/************************************************************
*
* graph::Dijstra(string start)
*___________________________________________________________
* This function finds the shortest path to all destination
*   from given starting point
*___________________________________________________________
* INPUTS:
*   string start    -   starting point
*
* OUTPUTS:
*   None
*
*************************************************************/

/************************************************************
*
* MST_Prim(string start)
*___________________________________________________________
* This function finds MST using prim's algorithm
*___________________________________________________________
* INPUTS:
*   string start    -   starting point
*
* OUTPUTS:
*   None
*
*************************************************************/

/************************************************************
*
* graph::MST_Kruskal()
*___________________________________________________________
* This function finds MST using Kruskal's algorithm
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/

/************************************************************
*
* construct_graph()
*___________________________________________________________
* This function construct the entire graph
*___________________________________________________________
* INPUTS:
*   None
*
* OUTPUTS:
*   None
*
*************************************************************/
#endif // DIJKSTRA_H
