#include <vector>
#include <string>
#include <algorithm>
#include <iterator> 
#include <string>
#include <regex>
#include <set>
#include <iostream>

#include "../POO/Details.hpp"
#include "ConexionesComputadora.h"

/**
 * Class to manage ConexionesComputadora 
 * Just to try reduce ejecution times
 */
#pragma once

using namespace std;

class ConnectionManager{
private:
    // Vector to save all IP's and their 
    // in/out directions
    set <ConexionesComputadora*> allConnections; // Lo cambié a set, para más rápido
    vector <Details> allDetails;
    //To get the last number on the IP address
    string getLocalIP(string);

    // bool isInAllConnections(Details);
    
public:
    ConnectionManager();
    ConnectionManager(vector<Details>);

    vector <string> get_IP_outgoingConct(string);
    vector <string> get_IP_incommingConct(string);
    

    //Search by IP last number
    void get_IPinfo(string);

    //Sumary
    set <ConexionesComputadora*> get_allConnections();

    void registerConnections();

    void fill_allConnections(bool);

};