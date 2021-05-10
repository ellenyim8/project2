#include "stadium.h"

/*****************************************************
 * Stadium()
 *
 *  default constructor; receives no parameters and
 *  returns nothing
 * --------------------------------------------------
 *  Pre-conditions: none
 * --------------------------------------------------
 *  Post-conditions: initializes an empty CTOR
*****************************************************/
Stadium::Stadium()
{
    _stadium_name = "no_name";
    team = "no_team";
    street = "no_street";
    city = "no_city";
    phoneNo = "no_number";
    capacity = 0;
    national = false;
}

void Stadium::set_stadium_name(string name)
{
    _stadium_name = name;
}

void Stadium::set_team(string new_team)
{
    team = new_team;
}

void Stadium::set_street(string new_street)
{
    street = new_street;
}

void Stadium::set_city(string new_city)
{
    city = new_city;
}

void Stadium::set_phone_num(string new_no)
{
    phoneNo = new_no;
}

void Stadium::set_capacity(int new_cap)
{
    capacity = new_cap;
}

void Stadium::set_national(bool new_national_l)
{
    national = new_national_l;
}

void Stadium::set_open(date new_open)
{
    opened = new_open;
}

string Stadium::get_stadium_name()
{
    return _stadium_name;
}

string Stadium::get_team()
{
    return team;
}

string Stadium::get_street()
{
    return street;
}

string Stadium::get_city()
{
    return city;
}

string Stadium::get_number()
{
    return phoneNo;
}

int Stadium::get_capacity()
{
    return capacity;
}

bool Stadium::is_national()
{
    return national;
}

date Stadium::get_opened()
{
    return opened;
}

ostream& operator <<(ostream& outs, Stadium& s)
{
    outs << s._stadium_name << "\n" << s.team << "\n" << s.street << "\n"
         << s.city << "\n" << s.phoneNo << "\n" << s.opened << "\n"
         << s.capacity << "\n";
    if (s.national)
        outs << "National League\n";
    else
        outs << "American League\n";

    return outs;
}

void Stadium::operator=(Stadium other)
{
    _stadium_name = other._stadium_name;
    team = other.team;
    street = other.street;
    city = other.city;
    phoneNo = other.phoneNo;
    capacity = other.capacity;
    opened = other.opened;
    national = other.national;
}

