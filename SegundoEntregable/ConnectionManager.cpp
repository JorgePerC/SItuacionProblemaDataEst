
#include "ConnectionManager.h"


ConnectionManager::ConnectionManager(/* args */){
    cout << "Missing Vector" << endl;
}

ConnectionManager::ConnectionManager(vector <Details> allregisters){
    this -> allDetails = allregisters;
}

//Regresa un vector con las conexiones entrantes del Ip dado
vector <string> ConnectionManager :: get_IP_incommingConct(string IP){
    for (auto element : allConnections){
        if (IP.compare(element -> get_IP()) == 0){
            cout <<"Se ecncontró! Mostrando registros" << endl;
            return element -> get_incommingConct();
        }
    }
    vector <string> empty;
    return empty;
}

//Regresa un vector con las conexiones salientes del Ip dado
vector <string> ConnectionManager :: get_IP_outgoingConct(string IP){
    for (auto element : allConnections){
        if (IP.compare(element -> get_IP()) == 0){
            return element -> get_outgoingConct();
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

// Returns a vector with the desired data
set <ConexionesComputadora*> ConnectionManager :: get_allConnections (){
    return allConnections;
}

//
void ConnectionManager::registerConnections(){
    for (auto d : allDetails){
        if (d.getDestinationName().compare("-") == 0 || d.getSourceName().compare("-") == 0 ){
            continue;
        }

        for (auto cnct : allConnections){
            // cout << "Tryng to connect " << endl;
            // cout << d.getSourceIP()  << " -> " << 
            // d.getDestinationIP()<<" ==? "<<cnct -> get_IP() << " " 
            //     << (d.getSourceIP().compare(cnct -> get_IP()) == 0) <<
            //     ", " << ((d.getDestinationIP().compare(cnct -> get_IP()) == 0)) << endl;

            if (d.getSourceIP().compare(cnct -> get_IP()) == 0){
                // cout << "Sale Cnn" << endl;
                cnct -> add_outgoingConct (d);
                break;
            }
            if (d.getDestinationIP().compare(cnct -> get_IP()) == 0){
                // cout << "Entra Cnn" << endl;
                
                cnct -> add_incommingConct(d);
                break;
            }
        }
    }
    
}

void ConnectionManager::fill_allConnections (bool isExternal = false){
    for (auto detail : allDetails ){
        //Para no meter los sin nombre
        if (detail.getDestinationName().compare("-") == 0 || detail.getSourceName().compare("-") == 0 ){
            continue;
        }
        this -> allConnections.insert(new ConexionesComputadora (detail, isExternal));
    }
}

// bool ConnectionManager:: isInAllConnections(Details d){
//     for (auto cnt : allConnections ){
//         if (d.getSourceIP().compare(cnt.get_IP()) == 0
//             || d.getSourceName().compare(cnt.get_name()) == 0){
//             return true;
//         }
//     }    
//     return false;
// }