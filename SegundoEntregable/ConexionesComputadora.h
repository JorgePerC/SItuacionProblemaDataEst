#include <string>
#include <vector>
#include "../POO/Details.hpp"

#pragma once

using namespace std;


class ConexionesComputadora {

private:
    // Attributes
    string IP, name;

    //Vectors 
    vector <string> incommingConct;
    vector <string> outgoingConct; 

public: 
    //SourceIp, SourceName : vector <Details>
    ConexionesComputadora ();
    ConexionesComputadora (string, string);
    //Returns incomingConct *Puedo cambiar la estructura
    vector <string> const get_incommingConct();
    vector <string> const get_outgoingConct();

    string const get_name();
    string const get_IP();

    //Add a registers to the ip
    void add_incommingConct(Details*);
    void add_outgoingConct(Details*);
    
    
};
