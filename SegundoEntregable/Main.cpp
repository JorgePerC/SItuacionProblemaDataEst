#include <iostream>
#include <string>
#include "../POO/CSV.hpp"
#include "../POO/Details.hpp"
#include "ConnectionManager.h"

using namespace std;

int main(int argc, char const *argv[]){

    string filePath = "../Files/equipo4_try.csv";
    
    CSV file = CSV(filePath);
    
    vector<Details> detalles = file.read_csv_details();

    ConnectionManager datos ();

    for ( Details d :detalles){
        cout << d << endl;
    }

    cout << "Hola" << endl;
    return 0;
}
