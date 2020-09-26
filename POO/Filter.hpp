//
//  Filter.hpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#ifndef Filter_hpp
#define Filter_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Details.hpp"

using namespace std;

class Filter {
    
private:
    vector<Details> details;
    
public:
    Filter();
    Filter(vector<Details> details);
    vector<Details> quicksort(bool sort(Details a, Details b));
    vector<Details> quicksort(int first, int last, bool sort(Details a, Details b));
    
};

#endif /* Filter_hpp */
