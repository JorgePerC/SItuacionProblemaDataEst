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

void ConexionesComputadora::add_incommingConct(Details* connectionRegister){
    incommingConct.push_back(connectionRegister -> getSourceIP());
}

void ConexionesComputadora::add_outgoingConct(Details* connectionRegister){
    outgoingConct.push_back(connectionRegister -> getDestinationIP());
}

string const ConexionesComputadora::get_IP(){
    return this -> IP;
}

string const ConexionesComputadora::get_name(){
    return this -> name;
}

vector <string> const ConexionesComputadora :: get_incommingConct(){
    return incommingConct;
}
vector <string> const ConexionesComputadora :: get_outgoingConct(){
    return outgoingConct;
}


