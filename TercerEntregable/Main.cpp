#include <iostream>
#include <string>
#include "../POO/CSV.hpp"
#include "../POO/Details.hpp"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


map<string,int> conexionesPorDia(string date) {
    // Sacar los datos del csv
    string filePath = "../Files/equipo4.csv";
    CSV file = CSV(filePath);
    vector<Details> details = file.read_csv_details();
    // Inicializar el map
    map<string,int> conexiones;
    for (auto detail : details) {
        if (detail.getDate() == date) {
            if (detail.getDestinationName() != "-" && detail.getDestinationName() != "reto.com") {
                if ( conexiones.find(detail.getDestinationName()) == conexiones.end() ) {
                  // not found
                  pair <string, int> p1;
                    p1.first = detail.getDestinationName();
                    p1.second = 1;
                    conexiones.insert( p1 );
                } else {
                  // found
                    conexiones[detail.getDestinationName()] ++;
                }
            }
        }
    }
    
    return conexiones;
}

bool isGreaterThan(pair<string, int>& a, pair<string, int>& b) { 
    return a.second > b.second; 
} 

void top(int n, string date) {
    map<string,int> conexiones = conexionesPorDia(date);
    // sort conexiones
    vector<pair<string, int> > sitiosEnFecha; 
    for (auto it : conexiones) { 
        sitiosEnFecha.push_back(it); 
    } 
  
    // Ordenar el vector por repeticiones
    sort(sitiosEnFecha.begin(), sitiosEnFecha.end(), isGreaterThan); 

    // Mostrar n elementos
    for (auto item : sitiosEnFecha){
        // Para romper el ciclo
        if (n<1) break;
        cout << item.first<< ' ' << item.second << endl;
        n--;
    }
    
}

vector <string> getAllDays(){
    
    string filePath = "../Files/equipo4.csv";
    // Usar clase CSV para abrir el archivo
    CSV file = CSV(filePath);
    return file.getUniqueRowData();
}

void pregunta2 (){
    
}

void pregunta3 (){
    vector <string> days = getAllDays();
    for (auto t : days){
        top(5, t);
        cout << "+++" << endl;
    }
}

int main (){
    auto myMap = conexionesPorDia("10-8-2020");

    cout << "------" << endl;

    cout << "Pregunta: "<< "¿Existe algún sitio que se mantenga en el top 5 todos los días? " << endl;
    //Respuesta obtenida con el método de la pregunta 3
    cout << "\tSí, el freemailserver.com, siempre aparece en primera posición" << endl;


    cout << "--------------" << endl;
    cout << "Pregunta: "<< "¿Existe algún sitio que entre al top 5 a partir de un día y de ahí aparezca en todos los días subsecuentes?" << endl;
    cout << "No" << endl;



    cout << "--------------" << endl;
    cout << "Pregunta: "<< "¿Existe algún sitio que aparezca en el top 5 con una cantidad más alta de trafico que lo normal? " << endl;
    // pregunta3(); //No lo corremos para no llenar el output
    cout << "\tSí, el freemailserver.com" << endl;

    cout << "--------------" << endl;
    
    // vector <string> rows = getAllDays();
    // for (auto i : rows){
    //     cout << i << endl;

    // }

} 