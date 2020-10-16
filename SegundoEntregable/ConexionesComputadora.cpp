#include "ConexionesComputadora.h"
#include "../POO/Details.hpp"

using namespace std;

ConexionesComputadora::ConexionesComputadora(){
    this -> IP = "";
    this -> name = "";
}

ConexionesComputadora::ConexionesComputadora(string name, string IP){
    this -> IP = IP;
    this -> name = name;
}

void ConexionesComputadora::add_incommingConct(Details* register){
    incommingConct.push_back(register -> );
}

void ConexionesComputadora::add_outgoingConct(Details* register){
    incommingConct.push_back(register -> getDestinationPort());
}

string const ConexionesComputadora::get_IP(){
    return this -> IP;
}

string const ConexionesComputadora::get_name(){
    return this -> name;
}

vector <string> const ConexionesComputadora :: get_incommingConct(){

}
vector <string> const ConexionesComputadora :: get_outgoingConct(){
    
}

/**
 * Class to manage ConexionesComputadora 
 * Just to try reduce ejecution times
 */
