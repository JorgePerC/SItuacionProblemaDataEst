
#include "ConnectionManager.h"



ConnectionManager::ConnectionManager(/* args */){
    cout << "Missing Vector" << endl;
}

ConnectionManager::ConnectionManager(vector <Details> allregisters){
    this -> allDetails = allregisters;
}




vector <string> ConnectionManager :: get_IP_incommingConct(string IP){
    for (auto element : allConnections){
        // PONER EQUALS Bien
        if (IP == element.get_IP()){
            return element.get_incommingConct();
        }
    }
}

vector <string> ConnectionManager :: get_IP_outgoingConct(string IP){
    for (auto element : allConnections){
        // PONER EQUALS Bien
        if (IP == element.get_IP()){
            return element.get_outgoingConct();
        }
    }
}


string ConnectionManager:: getLocalIP (string completeIp){
    stringstream test(completeIp);
    string segment;
    vector<string> seglist;

    while(getline(test, segment, '.')){
        seglist.push_back(segment);
    }
    return seglist[seglist.size()-1];
}

void ConnectionManager :: get_IPinfo (string IP){
    //Print incommming and and outgoingconnection
}

vector <ConexionesComputadora> ConnectionManager :: get_allConnections (){
    return allConnections;
}

void ConnectionManager::registerConnections(Details* d){
    for (auto element : allConnections){
        // PONER EQUALS Bien
        if (d -> getSourceIP () == element.get_IP()){
            element.add_outgoingConct (d);
        }
        if (d ->getDestinationIP() == element.get_IP()){
            element.add_incommingConct(d);
        }
    }
}