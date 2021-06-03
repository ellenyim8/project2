#include "Dijkstra.h"
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
graph::graph()
{
    construct_graph();
    size = 30;
}

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
bool graph::isEmpty()
{
    return size == 0;
}

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
lists<city> graph::incidentEdges(string city)
{
    // search thru the list and find all given city's edge
    for(int i=0; i<size; i++)
        if(adj_list[i].at(0).name == city)
            return adj_list[i];
    cout << "Cant find given name \" " << city.data() << "\"" << endl;
    exit(0);
}

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
int graph::search_edge(lists<edge> l, string city)
{
    // go thru the list and find the edge contains give ncity
    for(int i=0; i<l.size(); i++)
    {
        //cout << l.at(i).city_1.data() << " " << l.at(i).city_2.data() << endl;
        if(l.at(i).city_1 == city || l.at(i).city_2 == city)
        {
            return i;
        }
    }
    return -1;
}

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
bool graph::isCycle(lists<edge> l, edge e)
{
    // find if given edge's two cities have all been visited
    lists<string> set;
    string prev;
    int e_c1_pos = search_edge(l, e.city_1);
    int e_c2_pos = search_edge(l, e.city_2);

    // if not, store one of it city's route in a set
    if(e_c1_pos == -1 || e_c2_pos == -1)
        return false;
    else
    {
        prev = e.city_1;

        while(e_c1_pos != -1)
        {
            set.push_back(l.at(e_c1_pos).city_1);
            set.push_back(l.at(e_c1_pos).city_2);

            if(prev == l.at(e_c1_pos).city_1)
                prev = l.at(e_c1_pos).city_2;

            l.remove(l.at(e_c1_pos));
            e_c1_pos = search_edge(l, prev);
        }
    }

    // search if two cities are all in the set
    return search_edge(l, e.city_1) != -1 && search_edge(l, e.city_2) != -1;
}

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
int graph::indexOf(string c)
{
    // go thru the list and find given city
    for(int i=0; i<size; i++)
        if(adj_list[i].at(0).name == c)
            return i;

    cout << c.data() << "is not found" << endl;
    exit(0);
}

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
int graph::cost_of(string c1, string c2)
{
    // find all edges of c1 and see if c2 is one of them, and return distance
    lists<city> temp = incidentEdges(c1);

    for(int i=0; i<temp.size(); i++)
        if(temp.at(i).name == c2)
            return temp.at(i).weight;

    cout << "no connection between " << c1.data() << " and " << c2.data()
         << endl;
    return -1;
}

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
void graph::print_path(int arr[], int size, int index,vector<string>& vec)
{
    if(index == -1)
        return;
    if(arr[index] == -1){
        vec.push_back(adj_list[index].at(0).name);
    }
    else
    {
        print_path(arr, size, arr[index],vec);
        vec.push_back(adj_list[index].at(0).name);
    }
}

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
void graph::Dijstra(string start,vector<pair<int,vector<string>>>& vec)
{
    int max_num = 99999;    // this is the infinity figure
    lists<int> shortest;     // this list stores shortest path
    int p[size];              // this is the previous city list
    int c[size];              // this is cost list
    int indexOfStart = indexOf(start);
    c[indexOfStart] = 0;

    // set cost list all to infinity and previous list to none
    for(int i=0; i<size; i++)
    {
        p[i] = -1;
        if(i != indexOfStart)
            c[i] = max_num;
    }

    while(shortest.size() != size)
    {
        int smallest = 0;
        int temp = max_num;
        int j, cost_s_to_j;

        // find shortest path that is not in S
        for(int i=0; i<size; i++)
            if(c[i] < temp && !shortest.find(i))
            {
                temp = c[i];
                smallest = i;
            }
        shortest.push_back(smallest);

        // updata cost list to its least
        for(int i=1; i<adj_list[smallest].size(); i++)
        {
            j = indexOf(adj_list[smallest].at(i).name);
            if(!shortest.find(j))
            {
                cost_s_to_j = cost_of(adj_list[smallest].at(0).name,
                                          adj_list[j].at(0).name);
                if(c[smallest] + cost_s_to_j < c [j])
                {
                    c[j] = c[smallest] + cost_s_to_j;
                    p[j] = smallest;
                }
            }
        }
    }


    // prints out the shortest path
    for(int i=0; i<size; i++)
    {
        vector<string> v;
        print_path(p, size, p[i],v);
        v.push_back(adj_list[i].at(0).name);
        vec.push_back(make_pair(c[i],v));
    }
}

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
void graph::construct_graph()
{

    adj_list[0].push_back(city("Dodger Stadium", 0));
    adj_list[0].push_back(city("Angel Stadium", 0));
    adj_list[0].push_back(city("AT&T Park", 340));
    adj_list[0].push_back(city("Target Field", 1500));
    adj_list[0].push_back(city("Petco Park", 110));

    adj_list[1].push_back(city("Angel Stadium", 0));
    adj_list[1].push_back(city("Dodger Stadium", 0));

    adj_list[2].push_back(city("AT&T Park", 0));
    adj_list[2].push_back(city("Dodger Stadium", 340));
    adj_list[2].push_back(city("Chase Field", 650));
    adj_list[2].push_back(city("SafeCo Field", 680));
    adj_list[2].push_back(city("O.co Coliseum", 0));

    adj_list[3].push_back(city("O.co Coliseum", 0));
    adj_list[3].push_back(city("AT&T Park", 0));

    adj_list[4].push_back(city("Petco Park", 0));
    adj_list[4].push_back(city("Dodger Stadium", 110));
    adj_list[4].push_back(city("Coors Field", 830));
    adj_list[4].push_back(city("Chase Field", 300));

    adj_list[5].push_back(city("SafeCo Field", 0));
    adj_list[5].push_back(city("AT&T Park", 680));
    adj_list[5].push_back(city("Rogers Center", 2070));
    adj_list[5].push_back(city("Target Field", 1390));

    adj_list[6].push_back(city("Chase Field", 0));
    adj_list[6].push_back(city("AT&T Park", 650));
    adj_list[6].push_back(city("Petco Park", 300));
    adj_list[6].push_back(city("Coors Field", 580));
    adj_list[6].push_back(city("Rangers Ballpark", 870));
    adj_list[6].push_back(city("Minute Maid Park", 1115));

    adj_list[7].push_back(city("Coors Field", 0));
    adj_list[7].push_back(city("Petco Park", 830));
    adj_list[7].push_back(city("Chase Field", 580));
    adj_list[7].push_back(city("Kauffman Stadium", 560));
    adj_list[7].push_back(city("Rangers Ballpark", 650));

    adj_list[8].push_back(city("Target Field", 0));
    adj_list[8].push_back(city("SafeCo Field", 1390));
    adj_list[8].push_back(city("Dodger Stadium", 1500));
    adj_list[8].push_back(city("Miller Park", 300));
    adj_list[8].push_back(city("Busch Stadium", 465));

    adj_list[9].push_back(city("Kauffman Stadium", 0));
    adj_list[9].push_back(city("Coors Field", 560));
    adj_list[9].push_back(city("US Cellular Field", 415));
    adj_list[9].push_back(city("Busch Stadium", 235));
    adj_list[9].push_back(city("Rangers Ballpark", 460));

    adj_list[10].push_back(city("Rangers Ballpark", 0));
    adj_list[10].push_back(city("Chase Field", 870));
    adj_list[10].push_back(city("Coors Field", 650));
    adj_list[10].push_back(city("Kauffman Stadium", 460));
    adj_list[10].push_back(city("Turner Field", 740));
    adj_list[10].push_back(city("Minute Maid Park", 230));

    adj_list[11].push_back(city("Minute Maid Park", 0));
    adj_list[11].push_back(city("Chase Field", 1115));
    adj_list[11].push_back(city("Rangers Ballpark", 230));
    adj_list[11].push_back(city("Busch Stadium", 680));
    adj_list[11].push_back(city("Tropicana Field", 790));
    adj_list[11].push_back(city("Marlins Park", 965));

    adj_list[12].push_back(city("Busch Stadium", 0));
    adj_list[12].push_back(city("Target Field", 465));
    adj_list[12].push_back(city("Kauffman Stadium", 235));
    adj_list[12].push_back(city("Minute Maid Park", 680));
    adj_list[12].push_back(city("Great American Ballpark", 310));

    adj_list[13].push_back(city("Miller Park", 0));
    adj_list[13].push_back(city("Target Field", 300));
    adj_list[13].push_back(city("Wrigley Field", 80));
    adj_list[13].push_back(city("Rogers Center", 430));

    adj_list[14].push_back(city("Wrigley Field", 0));
    adj_list[14].push_back(city("Miller Park", 80));
    adj_list[14].push_back(city("US Cellular Field", 0));
    adj_list[14].push_back(city("Comerica Park", 240));
    adj_list[14].push_back(city("Great American Ballpark", 250));

    adj_list[15].push_back(city("US Cellular Field", 0));
    adj_list[15].push_back(city("Wrigley Field", 0));
    adj_list[15].push_back(city("Kauffman Stadium", 415));

    adj_list[16].push_back(city("Comerica Park", 0));
    adj_list[16].push_back(city("Wrigley Field", 240));
    adj_list[16].push_back(city("Rogers Center", 210));
    adj_list[16].push_back(city("Progressive Field", 90));

    adj_list[17].push_back(city("Great American Ballpark", 0));
    adj_list[17].push_back(city("Busch Stadium", 310));
    adj_list[17].push_back(city("Wrigley Field", 250));
    adj_list[17].push_back(city("Progressive Field", 225));
    adj_list[17].push_back(city("PNC Park", 260));
    adj_list[17].push_back(city("Turner Field", 375));
    adj_list[17].push_back(city("Tropicana Field", 790));

    adj_list[18].push_back(city("Turner Field", 0));
    adj_list[18].push_back(city("Rangers Ballpark", 740));
    adj_list[18].push_back(city("Great American Ballpark", 375));
    adj_list[18].push_back(city("Nationals Park", 560));
    adj_list[18].push_back(city("Marlins Park", 600));

    adj_list[19].push_back(city("Progressive Field", 0));
    adj_list[19].push_back(city("Comerica Park", 90));
    adj_list[19].push_back(city("Great American Ballpark", 225));
    adj_list[19].push_back(city("PNC Park", 115));

    adj_list[20].push_back(city("Rogers Center", 0));
    adj_list[20].push_back(city("SafeCo Field", 2070));
    adj_list[20].push_back(city("Miller Park", 430));
    adj_list[20].push_back(city("Comerica Park", 210));
    adj_list[20].push_back(city("Fenway Park", 430));
    adj_list[20].push_back(city("PNC Park", 225));

    adj_list[21].push_back(city("PNC Park", 0));
    adj_list[21].push_back(city("Great American Ballpark", 260));
    adj_list[21].push_back(city("Progressive Field", 115));
    adj_list[21].push_back(city("Rogers Center", 225));
    adj_list[21].push_back(city("Yankee Stadium", 315));
    adj_list[21].push_back(city("Nationals Park", 195));

    adj_list[22].push_back(city("Fenway Park", 0));
    adj_list[22].push_back(city("Rogers Center", 430));
    adj_list[22].push_back(city("Marlins Park", 1255));
    adj_list[22].push_back(city("Citi Field", 195));

    adj_list[23].push_back(city("Citi Field", 0));
    adj_list[23].push_back(city("Yankee Stadium", 0));
    adj_list[23].push_back(city("Fenway Park", 195));

    adj_list[24].push_back(city("Yankee Stadium", 0));
    adj_list[24].push_back(city("PNC Park", 315));
    adj_list[24].push_back(city("Citizens Bank Park", 80));
    adj_list[24].push_back(city("Citi Field", 0));

    adj_list[25].push_back(city("Citizens Bank Park", 0));
    adj_list[25].push_back(city("Nationals Park", 90));
    adj_list[25].push_back(city("Yankee Stadium", 80));

    adj_list[26].push_back(city("Camden Yards", 0));
    adj_list[26].push_back(city("Nationals Park", 0));

    adj_list[27].push_back(city("Nationals Park", 0));
    adj_list[27].push_back(city("Turner Field", 560));
    adj_list[27].push_back(city("PNC Park", 195));
    adj_list[27].push_back(city("Camden Yards", 0));
    adj_list[27].push_back(city("Citizens Bank Park", 90));
    adj_list[27].push_back(city("Marlins Park", 930));

    adj_list[28].push_back(city("Marlins Park", 0));
    adj_list[28].push_back(city("Minute Maid Park", 965));
    adj_list[28].push_back(city("Turner Field", 600));
    adj_list[28].push_back(city("Tropicana Field", 210));
    adj_list[28].push_back(city("Nationals Park", 930));
    adj_list[28].push_back(city("Fenway Park", 1255));

    adj_list[29].push_back(city("Tropicana Field", 0));
    adj_list[29].push_back(city("Minute Maid Park", 790));
    adj_list[29].push_back(city("Great American Ballpark", 790));
    adj_list[29].push_back(city("Marlins Park", 210));

}











