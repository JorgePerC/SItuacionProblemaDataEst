#include <iostream>
#include <string>
#include "../POO/CSV.hpp"
#include "../POO/Details.hpp"

using namespace std;

int main(int argc, char const *argv[]){

    string filePath = "../Files/equipo4_try.csv";
    
    CSV file = CSV(filePath);
    
    vector<Details> detalles = file.read_csv_details();

    cout << "Hola" << endl;
    return 0;
}
