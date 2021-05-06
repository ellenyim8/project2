#include "souvenircontainer.h"
#include "cassert"

/****************************************************
 * SouvenirContainer()
 *
 * default constructor; receives no parameters
 * -------------------------------------------------
 * PRE-CONDITIONS: none
 * POST-CONDITIONS: souvenirs initialized with size
 * 50; souvenir_count initialized to 0
****************************************************/
SouvenirContainer::SouvenirContainer()
    : souvenir_count(0)
{
    souvenirs = new Souvenir[20];
}

/****************************************************
 * ~SouvenirContainer()
 *
 * destructor; deallocates souvenir attribute
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: nothing
****************************************************/
SouvenirContainer::~SouvenirContainer()
{
    delete[] souvenirs;
}

/****************************************************
 * bool contains(string& item)
 *
 * accessor; loops the souvenir array list to see
 * if given (string) item is found.
 * -------------------------------------------------
 *  Parameters: (string&) item
 * -------------------------------------------------
 *  Returns: bool (true) if string& found, (false)
 *      if not found
****************************************************/
bool SouvenirContainer::contains(const string &item)
{
    if (get_souvenirs_count() == 0) return false;
    for (int i=0; i<get_souvenirs_count(); i++) {
        if (souvenirs[i].get_item() == item)
            return true;
    }
    return false;
}

/****************************************************
 * void add_souvenir(const Souvenir& new_souvenir)
 *
 *  mutator; adds souvenir to list
 * -------------------------------------------------
 *  Parameters: souvenir object
 * -------------------------------------------------
 *  Returns: nothing
****************************************************/
void SouvenirContainer::add_souvenir(const Souvenir &new_souvenir)
{
    if (!contains(new_souvenir.get_item())) {
        if (get_souvenirs_count() < 50) {
            souvenirs[souvenir_count] = new_souvenir;
            souvenir_count++;
        }
        else {
            int size = get_souvenirs_count() * 2;
            Souvenir *temp;
            temp = new Souvenir[size];

            for (int i=0; i<get_souvenirs_count(); i++) {
                temp[i] = souvenirs[i];
            }
            delete[] souvenirs;
            souvenirs = new Souvenir[size];

            for (int i=0; i<get_souvenirs_count(); i++) {
                souvenirs[i] = temp[i];
            }
            souvenirs[get_souvenirs_count()] = new_souvenir;
            souvenir_count++;

            delete[] temp;
        }
    }
}

/****************************************************
 * void remove_souvenir(const string& item)
 *
 *  mutator; removes souvenir from list
 * -------------------------------------------------
 *  Parameters: (string&) item
 * -------------------------------------------------
 *  Returns: nothing
****************************************************/
void SouvenirContainer::remove_souvenir(const string &item)
{
    if (!contains(item))
        return;
    for (int i=0; i<get_souvenirs_count(); i++) {
        if (souvenirs[i].get_item() == item) {
            for (int j=i; j<get_souvenirs_count(); j++) {
                souvenirs[j] = souvenirs[j+1];
            }
            souvenir_count--;
            break;
        }
    }

}

void SouvenirContainer::readFile(string name)
{
    ifstream in(name);
    if (!in.is_open())
        return;

    string input;
    while (getline(in, input))
    {
        double price;   // IN: file input souvenir price
        in >> price;
        in.ignore();

        int quantity;   // IN: file input souvenir quantity
        in >> quantity;
        in.ignore();

        Souvenir temp(input, price, quantity);
        this->add_souvenir(temp);
    }

    in.close();
}

void SouvenirContainer::outFile(string name)
{
    ofstream out(name);
    for (int i=0; i<this->get_souvenirs_count(); i++) {
        Souvenir temp = (*this)[i];
        out << temp.get_item() << "\n";
        out << temp.get_price() << " : " << temp.get_quantity() << "\n";
    }

}

