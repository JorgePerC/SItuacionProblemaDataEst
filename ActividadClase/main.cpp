#include <string>
#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include "../POO/Details.hpp"
#include "../POO/CSV.hpp"
#include "../SegundoEntregable/ConexionesComputadora.h"
#include "../SegundoEntregable/ConnectionManager.h"

using namespace std;

bool perteneceDominio(string addr){
    if (addr.find("reto.com") != string::npos) {
        return true;
    }
    return false;
}


int main(){

    CSV csv = CSV("../Files/equipo4.csv");
    vector<Details> details = csv.read_csv_details();

    set<pair <string, string>> setDirecciones; // No ponemos el método de ordenamiento, ", greater<int>"
    
    for(auto item : details){
        string n = item.getSourceName();
        string n2 = item.getDestinationName();
        string ip = item.getSourceIP();
        string ip2 = item.getDestinationIP();
        if (n.compare("-") == 0 || n2.compare("-") == 0){
            continue;
        }
        //Verificamos que no sean de reto.com
        if (!(perteneceDominio(n))){
            setDirecciones.insert(make_pair(n, ip));
        }
        if (!(perteneceDominio(n2))){
            setDirecciones.insert(make_pair(n2, ip2));
        }

    }
    
    // Print Set
    set<pair <string, string>>::iterator itr;
    cout << "Set de dominios : " << endl;
    for (itr = setDirecciones.begin(); itr != setDirecciones.end(); ++itr){
        cout << " | " << itr ->first << ", " << itr ->second;
    }
    cout << endl;
    cout << "-------------------------------------" << endl;
    
    /* PREGUNTA 3
    ConnectionManager* datos = new ConnectionManager(details);
    //Para obtener un set de las direcciones
    datos->fill_allConnections(false);
    
    // Para registrar entradas y salidas basados en datos
    datos -> registerConnections();

    cout << "Hizo registro" << endl;
    cout << endl;
    cout << "-------------------------------------" << endl;

    set <ConexionesComputadora*> connectionList = datos->get_allConnections();
    for (auto h : connectionList){
        if (h ->incommingConct.size() > 0){
            cout << *h << endl;
            h -> show_incommingConct();
        }
        
    }
    */
    //CUARTA PREGUNTA
    //Crear un connection Manager
    ConnectionManager* datos = new ConnectionManager(details);
    //Para obtener un set de las direcciones
    datos->fill_allConnections(true);
    
    // Para registrar entradas y salidas basados en datos
    datos -> registerConnections();

    cout << "Hizo registro" << endl;
    cout << endl;
    cout << "-------------------------------------" << endl;

    //set <ConexionesComputadora*> connectionList = datos->get_allConnections();
    // for (auto h : connectionList){
    //     cout << *h << endl;
    //     h -> show_incommingConct();
    // }
    vector <string> dtos = datos ->get_IP_incommingConct ("72.250.49.185");

    cout << "yellowpages.com " << endl;
    
    for (auto d : dtos ){
        cout << d << " | ";
    }
    cout << endl;

    dtos = datos ->get_IP_incommingConct ("143.174.187.243");
    cout << "yelp.com " << endl;
    for (auto d : dtos ){
        cout << d << " | ";
    }
    cout << endl;

    dtos = datos ->get_IP_incommingConct ("68.123.66.166");
    cout << "amazon.com " << endl;
    for (auto d : dtos ){
        cout << d << " | ";
    }
    cout << endl;

    dtos = datos ->get_IP_incommingConct ("161.89.224.58");
    cout << "euo5ychfvuhangmtt8uh.ru " << endl;
    for (auto d : dtos ){
        cout << d << " | ";
    }
    cout << endl;

    dtos = datos ->get_IP_incommingConct ("50.67.240.107");
    cout << "8w2v29sbezi1btcj4txw.com " << endl;
    for (auto d : dtos ){
        cout << d << " | ";
    }
    cout << endl;

    cout << "-------------------------------------" << endl;
    
 
    cout << "fin" << endl;
    //Diccionario
    // map <string, ConexionesComputadora> diccionario;

    // cout << "Llenar dic " << endl;
    // for (itr = setDirecciones.begin(); itr != setDirecciones.end(); ++itr){
    //     // Crear Pair
    //     pair <string, ConexionesComputadora> p1;
    //     p1.first = itr -> first;
    //     p1.second = ConexionesComputadora(itr -> first, itr -> second); 
    //     //LLENAR CONEXIONESCOMPUTADORA
    //     diccionario.insert(p1);
        
    // }

    delete datos;
    cout << endl;
    // pair <string, ConexionesComputadora()>


}