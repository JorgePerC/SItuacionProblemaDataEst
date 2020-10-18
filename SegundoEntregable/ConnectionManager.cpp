
#include "ConnectionManager.h"


ConnectionManager::ConnectionManager(/* args */){
    cout << "Missing Vector" << endl;
}

ConnectionManager::ConnectionManager(vector <Details> allregisters){
    this -> allDetails = allregisters;
}

vector <string> ConnectionManager :: get_IP_incommingConct(string IP){
    for (auto element : allConnections){
        if (IP.compare(element.get_IP()) == 0){
            return element.get_incommingConct();
        }
    }
    vector <string> empty;
    return empty;
}

vector <string> ConnectionManager :: get_IP_outgoingConct(string IP){
    for (auto element : allConnections){
        if (IP.compare(element.get_IP()) == 0){
            return element.get_outgoingConct();
        }
    }
    vector <string> empty;
    return empty;
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

void ConnectionManager::registerConnections(Details d){
    for (auto cnct : allConnections){
        cout << "Tryng to connect " << endl;
        cout << d.getSourceIP()  << " " << 
        d.getDestinationIP()<<" "<<cnct.get_IP() << " " 
            << (d.getSourceIP().compare(cnct.get_IP()) == 0) <<
            ", " << ((d.getDestinationIP().compare(cnct.get_IP()) == 0)) << endl;
        if (d.getSourceIP().compare(cnct.get_IP()) == 0){
            cout << "Entra" << endl;
            cnct.add_outgoingConct (d);
        }
        if (d.getDestinationIP().compare(cnct.get_IP()) == 0){
            cnct.add_incommingConct(d);
        }
    }
}

void ConnectionManager::fill_allConnections (){
    for (auto detail : allDetails ){
        if( !isInAllConnections(detail)){
            allConnections.push_back(ConexionesComputadora (detail));
        }
        
    }
}

bool ConnectionManager:: isInAllConnections(Details d){
    for (auto cnt : allConnections ){
        if (d.getSourceIP().compare(cnt.get_IP()) == 0
            || d.getSourceName().compare(cnt.get_name()) == 0){
            return true;
        }
    }    
    return false;
}