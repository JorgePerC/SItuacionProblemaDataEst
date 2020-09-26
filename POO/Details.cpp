//
//  Details.cpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#include "Details.hpp"

Details::Details() {
    this->date = "";
    this->time = "";
    this->sourceIp = "";
    this->sourcePort = -1;
    this->sourceName = "";
    this->destinationIp = "";
    this->destinationPort = -1;
    this->destinationName = "";
}

Details::Details(string date, string time, string sourceIp, int sourcePort, string sourceName, string destinationIp, int destinationPort, string destinationName) {
    this->date = date;
    this->time = time;
    this->sourceIp = sourceIp;
    this->sourcePort = sourcePort;
    this->sourceName = sourceName;
    this->destinationIp = destinationIp;
    this->destinationPort = destinationPort;
    this->destinationName = destinationName;
}

string Details::getDate() {
    return this->date;
}

string Details::getSourceName() {
    return this->sourceName;
}

string Details::getDestinationName() {
    return this->destinationName;
}

int Details::getDestinationPort() {
    return this->destinationPort;
}

bool Details::sortSourcePortAsc(Details a, Details b) {
    return a.sourcePort < b.sourcePort;
}

bool Details::sortSourcePortDesc(Details a, Details b) {
    return a.sourcePort > b.sourcePort;
}

bool Details::sortDestinationPortAsc(Details a, Details b) {
    return a.destinationPort < b.destinationPort;
}

bool Details::sortDestinationPortDesc(Details a, Details b) {
    return a.destinationPort > b.destinationPort;
}

ostream & operator << (ostream & os, const Details & detail) {
    os << detail.date << " | ";
    os << detail.time << " | ";
    os << detail.sourceIp << " | ";
    os << detail.sourcePort << " | ";
    os << detail.sourceName << " | ";
    os << detail.destinationIp << " | ";
    os << detail.destinationPort << " | ";
    os << detail.destinationName;
    os << endl;
    return os;
}
