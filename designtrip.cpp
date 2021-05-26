#include "designtrip.h"
shortestTrip::shortestTrip()
{
    total_distance = 0;
    num_of_cities = 0;
}

void shortestTrip::insert(pair<int,vector<string>> p)
{
    v.push_back(p);
}

void shortestTrip::insert_city(const string& s)
{
    cities.push_back(s);
    num_of_cities++;
}

bool shortestTrip::check(const string& s) const
{
    for(unsigned long long i = 0;i < cities.size();i++){
        if(cities[i] == s)
            return true;
    }
    return false;
}

void shortestTrip::set_trip()
{
    unsigned long long i,j;
    for(i = 0;i < v.size()-1;i++){
        for(j = 0;j < v.at(i).second.size()-1;j++)
            route.push_back(v.at(i).second[j]);
        total_distance += v.at(i).first;
    }
    for(unsigned long long k = 0;k < v.at(i).second.size();k++){
        route.push_back(v.at(i).second[k]);
    }
    total_distance += v.at(i).first;
}

