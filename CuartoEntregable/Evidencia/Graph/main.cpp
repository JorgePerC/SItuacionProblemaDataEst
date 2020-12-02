//
//  main.cpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#include <iostream>
#include "Graph.hpp"
#include "Details.cpp"
#include "CSV.cpp"
#include <algorithm>

vector<vector<string>> dateComputerA;
vector<vector<string>> dateComputerB;
vector<vector<string>> dateComputerC;

void met(int date, string destinationIp, string sourceIp){
    vector<string> aux = dateComputerA[date];
    if(!(find(aux.begin(), aux.end(), destinationIp) != aux.end())){
        dateComputerA[date].push_back(destinationIp);
    }

    if(destinationIp == "euo5ychfvuhangmtt8uh.ru"){
        vector<string> aux2 = dateComputerB[date];
        if(!(find(aux2.begin(), aux2.end(), sourceIp) != aux2.end())){
            dateComputerB[date].push_back(sourceIp);
        }
    }

    if(destinationIp == "17.40.194.75"){
        vector<string> aux3 = dateComputerC[date];
        if(!(find(aux3.begin(), aux3.end(), sourceIp) != aux3.end())){
            dateComputerC[date].push_back(sourceIp);
        }
    }
}

int main(int argc, const char * argv[]) {
    /* Crear un grafo */
    Graph<string, string> * graph = new Graph<string, string>();
    CSV csv = CSV("equipo4.csv");
    vector<Details> details = csv.read_csv_details();
    vector<Vertex<string, string> *> v;
    string ipCompany = "192.168.155.";
    int countConnections = 0;

    for(int i = 0; i < 10; i++){
        vector<string> aux;
        dateComputerA.push_back(aux);
        dateComputerB.push_back(aux);
        dateComputerC.push_back(aux);
    }

    for (auto detail : details) {
        string sourceIp = detail.getSourceIP();
        string destinationIp = detail.getDestinationIP();
        string fecha = detail.getDate();
        Vertex<string, string> * source = NULL;
        Vertex<string, string> * destination = NULL;

        if(sourceIp != "-" && destinationIp != "-"){
            if(sourceIp.find(ipCompany) != string::npos){
                if(fecha == "10-8-2020"){
                    met(0, destinationIp, sourceIp);
                } else if(fecha == "11-8-2020"){
                    met(1, destinationIp, sourceIp);
                } else if(fecha == "12-8-2020"){
                    met(2, destinationIp, sourceIp);
                } else if(fecha == "13-8-2020"){
                    met(3, destinationIp, sourceIp);
                } else if(fecha == "14-8-2020"){
                    met(4, destinationIp, sourceIp);
                } else if(fecha == "17-8-2020"){
                    met(5, destinationIp, sourceIp);
                } else if(fecha == "18-8-2020"){
                    met(6, destinationIp, sourceIp);
                } else if(fecha == "19-8-2020"){
                    met(7, destinationIp, sourceIp);
                } else if(fecha == "20-8-2020"){
                    met(8, destinationIp, sourceIp);
                } else {
                    met(9, destinationIp, sourceIp);
                }

                for(auto vect : v){
                    if(vect->getInfo() == sourceIp){
                        source = vect;
                    }

                    if(vect->getInfo() == destinationIp){
                        destination = vect;
                    }
                }
                
                if(source == NULL){
                    source = new Vertex<string, string>(sourceIp);
                    v.push_back(source);
                    graph->addVertex(source);
                }

                if(destination == NULL){
                    destination = new Vertex<string, string>(destinationIp);
                    v.push_back(destination);
                    graph->addVertex(destination);
                }
                graph->addEdge(source, destination, fecha);
            } else {
                if(destinationIp.find(ipCompany) != string::npos){
                    countConnections++;
                }
            }
        }
    }
    
    /* Visualizando el grafo */
    std::cout << *graph << std::endl;
    
    std::cout << "Count: " << countConnections << std::endl;

    for(auto data: dateComputerA){
        std::cout << data.size() <<endl;
    }
    std::cout << endl;
    for(auto data: dateComputerB){
        std::cout << data.size() <<endl;
    }
    std::cout << endl;
    for(auto data: dateComputerC){
        std::cout << data.size() <<endl;
    }

    /* Eliminar el grafo */
    delete graph;

    return 0;
}
