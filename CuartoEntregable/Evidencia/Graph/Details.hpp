//
//  Details.hpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#ifndef Details_hpp
#define Details_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

#pragma once
class Details {
    
private:
    string date;
    string time;
    string sourceIp;
    int sourcePort;
    string sourceName;
    string destinationIp;
    int destinationPort;
    string destinationName;
 
public:
    Details();
    Details(string date, string time, string sourceIp, int sourcePort, string sourceName, string destinationIp, int destinationPort, string destinationName);
    string getDate();
    string getSourceName();
    string getSourceIP();
    string getDestinationName();
    string getDestinationIP();
    int getDestinationPort();
    bool sortSourcePortAsc(Details a, Details b);
    bool sortSourcePortDesc(Details a, Details b);
    bool sortDestinationPortAsc(Details a, Details b);
    bool sortDestinationPortDesc(Details a, Details b);
    friend ostream & operator << (ostream & os, const Details & detail);
    
};

#endif /* Details_hpp */
