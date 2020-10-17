#include <vector>
#include <string>
#include "ConexionesComputadora.h"
#include <algorithm>
#include <iterator> 
#include <string>
#include <regex>
#include "../POO/Details.hpp"

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
    vector <ConexionesComputadora> allConnections;
    vector <Details> allDetails;
    //To get the last number on the IP address
    string getLocalIP(string);
    
public:
    ConnectionManager();
    ConnectionManager(vector<Details>);

    vector <string> get_IP_outgoingConct(string);
    vector <string> get_IP_incommingConct(string);
    

    //Search by IP last number
    void get_IPinfo(string);

    //Sumary
    vector <ConexionesComputadora> get_allConnections();

    void registerConnections(Details*);

};