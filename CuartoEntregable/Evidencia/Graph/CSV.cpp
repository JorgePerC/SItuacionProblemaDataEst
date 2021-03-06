//
//  CSV.cpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//
#include <algorithm>
#include "CSV.hpp"

CSV::CSV() {
    this->filename = "";
}
/**
 * Class to read file.csv
 * Arg:
 *  string filename -> name of the file to read
 */
CSV::CSV(string filename) {
    this->filename = filename;
}

/**
 * Returns a vector containg the information
 * from the file.csv. Vector type is Details.
 * Iterates over the file.csv lines.
 */
vector<Details> CSV::read_csv_details() {
    vector<Details> lines;
    ifstream file(this->filename);
    if(!file.is_open()) {
        throw runtime_error("File can't be opened.");
    } else {
    }
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string date;
        string time;
        string sourceIp;
        int sourcePort;
        string a;
        string aTest;
        string sourceName;
        string destinationIp;
        int destinationPort;
        string b;
        string bTest;
        string destinationName;
        
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, sourceIp, ',');
        getline(ss, a, ',');
        stringstream aconv(a);
        aconv >> aTest;
        if (aTest == "-") {
            stringstream conva("-1");
            conva >> sourcePort;
        } else {
            stringstream conva(a);
            conva >> sourcePort;
        }
        getline(ss, sourceName, ',');
        getline(ss, destinationIp, ',');
        getline(ss, b, ',');
        stringstream bconv(b);
        bconv >> bTest;
        if (bTest == "-") {
            stringstream convb("-1");
            convb >> destinationPort;
        } else {
            stringstream convb(b);
            convb >> destinationPort;
        }
        ss >> destinationName;
        
        lines.push_back(Details(date, time, sourceIp, sourcePort, sourceName, destinationIp, destinationPort, destinationName));
    }
    file.close();
    return lines;
}
vector<string> CSV::getUniqueRowData(){
    vector<string> lines;
    ifstream file(this->filename);
    if(!file.is_open()) {
        throw runtime_error("File can't be opened.");
    }
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string date;
        string time;
        string sourceIp;
        int sourcePort;
        string a;
        string aTest;
        string sourceName;
        string destinationIp;
        int destinationPort;
        string b;
        string bTest;
        string destinationName;
        
        getline(ss, date, ',');
        // getline(ss, time, ',');
        // getline(ss, sourceIp, ',');
        // getline(ss, a, ',');
        // stringstream aconv(a);
        // aconv >> aTest;
        // if (aTest == "-") {
        //     stringstream conva("-1");
        //     conva >> sourcePort;
        // } else {
        //     stringstream conva(a);
        //     conva >> sourcePort;
        // }
        // getline(ss, sourceName, ',');
        // getline(ss, destinationIp, ',');
        // getline(ss, b, ',');
        // stringstream bconv(b);
        // bconv >> bTest;
        // if (bTest == "-") {
        //     stringstream convb("-1");
        //     convb >> destinationPort;
        // } else {
        //     stringstream convb(b);
        //     convb >> destinationPort;
        // }
        // ss >> destinationName;
        if(lines.empty()){
            lines.push_back(date);
        }

        if(find(lines.begin(), lines.end(), date) != lines.end()) {
            /* do nothing */
        } else {
            lines.push_back(date);
        }
        
    }
    file.close();
    return lines;
}