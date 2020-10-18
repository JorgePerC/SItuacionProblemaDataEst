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

    ConnectionManager* datos = new ConnectionManager(detalles);

    datos -> fill_allConnections();

    vector <ConexionesComputadora> resultado = datos->get_allConnections();

    cout << "Tamaño: " << resultado.size() << endl;

    for (auto detail : detalles){
        datos -> registerConnections(detail);
    }

    
    for (auto res : resultado){
        cout << res << endl;
        res.show_incommingConct();
        res.show_outgoingConct();
    }



    delete datos;

    cout << "Hola" << endl;
    return 0;
}
