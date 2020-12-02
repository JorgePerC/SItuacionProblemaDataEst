#include <iostream>
#include <string>
#include "../POO/CSV.hpp"
#include "../POO/Details.hpp"
#include "ConnectionManager.h"

using namespace std;

int notmain33(int argc, char const *argv[]){
    /*


//    path al csv del equipo
    string filePath = "../Files/equipo4_try.csv";
//    usar clase CSV para abrir el archivo
    CSV file = CSV(filePath);
//    usar un vector para poner la información del csv en 'details'
    vector<Details> detalles = file.read_csv_details();
//    usar un objeto de ConnectionManager para manejar los datos de details
    ConnectionManager* datos = new ConnectionManager(detalles);
//    usar el método fill_allConnections para registrar las conexiones
    datos -> fill_allConnections(false);
//    loop para registar la conexión de cada detail en específico
    for (auto detail : detalles){
        datos -> registerConnections(detail);
    }

//    guardar las conexiones en resultado
    set <ConexionesComputadora> resultado = datos -> get_allConnections();
//    imprimir los resultados
    cout << "Tamaño: " << resultado.size() << endl;
    for (auto res : resultado){
        cout << res << endl;
        res.show_incommingConct();
        res.show_outgoingConct();
    }



    delete datos;
//    un saludo para acabar el programa
    cout << "Hola" << endl;

    */

   
    return 0;
}
