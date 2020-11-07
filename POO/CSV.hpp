//
//  CSV.hpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#ifndef CSV_hpp
#define CSV_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Details.hpp"

using namespace std;

class CSV {
    
private:
    string filename;

public:
    CSV();
    CSV(string filename);
    vector<Details> read_csv_details();
    vector<string> getUniqueRowData();
};

#endif /* CSV_hpp */
