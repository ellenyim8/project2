#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include "heap.h"
#include "Dijkstra.h"
#include <QPainter>
using namespace std;
extern Heap<Stadiums,StadiumsNameMin> MLS;
extern Heap<Stadiums,StringMin> MLS2;
extern Heap<Stadiums,StringMin> ALS;
extern Heap<Stadiums,StringMin> NLS;
extern vector<pair<string,QPoint>> positions;   // store all the stadiums and their positions

typedef pair<string,string> p;
typedef pair<p,int> dp;

/************************************************************
*
* Time Path
*   The path struct has 3 attributes, source,destination and
*     distance.
*
*************************************************************/
struct Path{
    Path(){}
    Path(dp entry)
        :source(entry.first.first),
          destination(entry.first.second),
          distance(entry.second){}
    string source;
    string destination;
    int distance;
    friend ostream& operator<<(ostream& os,const Path& p){
        os << "(" << p.source << "," << p.destination << ") " << p.distance << endl;
        return os;
    }
};

extern Dijkstra<string> MLSP;
//extern Dijkstra<string> ALSP;
extern vector<vector<string>> ALSP;
#endif // GLOBAL_H
