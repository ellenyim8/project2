#ifndef DESIGNTRIP_H
#define DESIGNTRIP_H
#include "Dijkstra.h"
class shortestTrip{
public:
    shortestTrip();
    void insert(pair<int,vector<string>> p);
    void insert_city(const string& s);
    bool check(const string& s) const;
    vector<pair<int,vector<string>>> get_trip() const{return v;}
    vector<string> get_cities() const{return cities;}
    int get_distance() const{return total_distance;}
    int get_noc() const{return num_of_cities;}
    vector<string> get_route() const{return route;}
    void set_trip();
private:
    vector<pair<int,vector<string>>> v;
    vector<string> cities;
    vector<string> route;
    int total_distance;
    int num_of_cities;
};

#endif // DESIGNTRIP_H
