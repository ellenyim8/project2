#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
using namespace std;
#include "date.h"

class Stadium
{
public:
    // CONSTRUCTORS
    Stadium();

    // MUTATORS
    void set_stadium_name(string name);
    void set_team(string new_team);
    void set_street(string new_street);
    void set_city(string new_city);
    void set_phone_num(string new_no);
    void set_capacity(int new_cap);
    void set_open(date new_open);
    void set_national(bool new_national_l);

    // ACCESSORS
    string get_stadium_name();
    string get_team();
    string get_street();
    string get_city();
    string get_number();
    int get_capacity();
    bool is_national();
    date get_opened();

    friend ostream& operator <<(ostream& outs, Stadium& s);
    void operator =(Stadium other);

private:
    string _stadium_name;
    string team;
    string street;
    string city;
    string phoneNo;
    date opened;
    int capacity;       // stadium capacity
    bool national;      // national league, if false then american league
};


/**************************************************
 * Stadium class
 * CONSTRUCTORS
 * Stadium()
 *
 *
 * ACCESSORS
 * string get_stadium_name() const
 *
 *
 * MUTATORS
 * void set_stadium_name(string name)
 *
**************************************************/

#endif // STADIUM_H
