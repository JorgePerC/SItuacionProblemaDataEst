#include "ConexionesComputadora.h"
ConexionesComputadora::ConexionesComputadora(const ConexionesComputadora &c) {
    this -> IP = c.IP; 
    this -> name = c.name; 
    this -> incommingConct = c.incommingConct;
    this -> outgoingConct = c.outgoingConct;
}

ConexionesComputadora::ConexionesComputadora(){
    this -> IP = "";
    this -> name = "";
}

ConexionesComputadora::ConexionesComputadora(string name, string IP){
    this -> IP = IP;
    this -> name = name;
}

ConexionesComputadora::ConexionesComputadora(Details d, bool isExternal = false){
    if (isExternal){
        this -> IP = d.getDestinationIP();
        this -> name = d.getDestinationName();
    }else{
        this -> IP = d.getSourceIP();
        this -> name = d.getSourceName();
    }
}

void ConexionesComputadora::add_incommingConct(Details connectionRegister){
    this -> incommingConct.push_back(connectionRegister.getSourceIP());
}

void ConexionesComputadora::add_outgoingConct(Details connectionRegister){
    this -> outgoingConct.push_back(connectionRegister.getDestinationIP());
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
bool operator < (const ConexionesComputadora & CC, const ConexionesComputadora & CC2) {
    return CC.IP < CC2.IP;
}

void ConexionesComputadora ::show_incommingConct(){
    // for (auto element: incommingConct){
    //     cout << "\t" << element << endl;
    // }
    cout << "------------- "<< incommingConct.size() << endl;
}

void ConexionesComputadora ::show_outgoingConct(){
    for (auto element: outgoingConct){
        cout << "\t" << element << endl;
    }
    cout << "-------------" << endl;
}