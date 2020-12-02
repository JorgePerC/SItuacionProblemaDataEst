#include <string>
#include <vector>
#include "../POO/Details.hpp"

#pragma once

using namespace std;


class ConexionesComputadora {

private:
    // Attributes
    string IP, name;

    

public: 
    //Vectors 
    vector <string> incommingConct;
    vector <string> outgoingConct; 

    //SourceIp, SourceName : vector <Details>
    ConexionesComputadora ();
    ConexionesComputadora (const ConexionesComputadora &c);
    ConexionesComputadora (string, string);
    ConexionesComputadora (Details, bool);
    //Returns incomingConct *Puedo cambiar la estructura
    vector <string> const get_incommingConct();
    vector <string> const get_outgoingConct();

    string const get_lastIP();
    string const get_name();
    string const get_IP();

    //Add a registers to the ip
    void add_incommingConct(Details);
    void add_outgoingConct(Details);

    void show_incommingConct();
    void show_outgoingConct();

    friend ostream & operator << (ostream & os, const ConexionesComputadora & CC);
    
    friend bool operator < (const ConexionesComputadora &, const ConexionesComputadora &);
    
};
