//
//  Filter.cpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#include "Filter.hpp"

Filter::Filter() {

}

Filter::Filter(vector<Details> details) {
    this->details = details;
}

vector<Details> Filter::quicksort(bool sort(Details a, Details b)) {
    int size = (int) this->details.size() - 1;
    return quicksort(0, size, sort);
}

vector<Details> Filter::quicksort(int first, int last, bool sort(Details a, Details b)) {
    int left = first;
    int right = last;
    Details fallback = this->details[first];
    if ( first < last) {
        while ( left < right) {
            while ((left < right) && !sort(fallback, this->details[left])) {
                left++;
            }
            while (sort(fallback, this->details[right])) {
                right--;
            }
            if ( left < right) {
                swap(this->details[left], this->details[right]);
            }
        }
        swap(this->details[left], this->details[right]);
        this->details = quicksort(first, right-1, sort);
        this->details = quicksort(left, last, sort);
    }
    return this->details;
}
