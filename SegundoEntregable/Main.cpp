#include <iostream>
#include <string>
#include "CSV.hpp"
#include "Details.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    string filePath = "../Files/equipo4_try.csv";
    
    CSV file = CSV(filePath);
    
    vector <Details> info = file.read_csv_details();

    return 0;
}
