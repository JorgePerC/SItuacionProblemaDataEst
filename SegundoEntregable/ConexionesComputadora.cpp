#include "ConexionesComputadora.h"

ConexionesComputadora::ConexionesComputadora(){
    this -> IP = "";
    this -> name = "";
}

ConexionesComputadora::ConexionesComputadora(string name, string IP){
    this -> IP = IP;
    this -> name = name;
}

ConexionesComputadora::ConexionesComputadora(Details d){
    this -> IP = d.getSourceIP();
    this -> name = d.getSourceName();
}

void ConexionesComputadora::add_incommingConct(Details connectionRegister){
    incommingConct.push_back(connectionRegister.getSourceIP());
}

void ConexionesComputadora::add_outgoingConct(Details connectionRegister){
    outgoingConct.push_back(connectionRegister.getDestinationIP());
}

string const ConexionesComputadora::get_IP(){
    return this -> IP;
}

string const ConexionesComputadora::get_name(){
    return this -> name;
}

string const ConexionesComputadora::get_lastIP(){
    return outgoingConct[outgoingConct.size()-1];
}

vector <string> const ConexionesComputadora :: get_incommingConct(){
    return incommingConct;
}
vector <string> const ConexionesComputadora :: get_outgoingConct(){
    return outgoingConct;
}

ostream & operator << (ostream & os, const ConexionesComputadora & CC) {
    os << CC.name << " | ";
    os << CC.IP << " | ";
    os << endl;
    return os;
}

void ConexionesComputadora ::show_incommingConct(){
    for (auto element: incommingConct){
        cout << "\t" << element << endl;
    }
    cout << "-------------" << endl;
}

void ConexionesComputadora ::show_outgoingConct(){
    for (auto element: outgoingConct){
        cout << "\t" << element << endl;
    }
    cout << "-------------" << endl;
}