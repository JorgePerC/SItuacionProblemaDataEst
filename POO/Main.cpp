//
//  Main.cpp
//  POO_Class
//
//  Created by Luis Alberto Fernández Castro on 21/09/20.
//  Copyright © 2020 LF Coding. All rights reserved.
//

#include <stdio.h>
#include "Details.hpp"
#include "CSV.hpp"
#include "Search.hpp"
#include "Filter.hpp"
#include <unistd.h>

using namespace std;


// ¿Cuántos registros tiene tu archivo?
long answerQ1(vector<Details> details) {
    return details.size();
}

// ¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?

void answerQ2(vector<Details> details, long *q1, string *q2) {
    *q1 = 0;
    vector<string> dates;
    for (auto detail : details) {
        if (find(dates.begin(), dates.end(), detail.getDate()) != dates.end()) {
            
        } else {
            dates.push_back(detail.getDate());
        }
    }
    sort(dates.begin(), dates.end());
    *q2 = dates[1];
    for (auto detail : details) {
        if (detail.getDate() == dates[1]) {
            *q1 += 1;
        }
    }
}

// ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?
vector<string> answerQ3(vector<Details> details) {
    vector<string> computers;
    bool a = false, b = false, c = false, d = false, e = false, f = false, g = false;
    for (auto detail : details) {
        if (detail.getSourceName() == "jeffrey.reto.com" && !a) {
            computers.push_back("Jeffrey");
            a = true;
        } else if (detail.getSourceName() == "betty.reto.com" && !b) {
            computers.push_back("Betty");
            b = true;
        } else if (detail.getSourceName() == "katherine.reto.com" && !c) {
            computers.push_back("Katherine");
            c = true;
        } else if (detail.getSourceName() == "scott.reto.com" && !d) {
            computers.push_back("Scott");
            d = true;
        } else if (detail.getSourceName() == "benjamin.reto.com" && !e) {
            computers.push_back("Benjamin");
            e = true;
        } else if (detail.getSourceName() == "samuel.reto.com" && !f) {
            computers.push_back("Samuel");
            f = true;
        } else if (detail.getSourceName() == "raymond.reto.com" && !g) {
            computers.push_back("Raymond");
            g = true;
        }
    }
    return computers;
}

// ¿Cuál es la dirección de la red interna de la compañía?
string answerQ4(vector<Details> details) {
    string s = "", x;
    for (auto detail : details) {
        if (s == "") {
            stringstream ss(detail.getSourceName());
            getline(ss, x, '.');
            ss >> s;
        }
    }
    return s;
}

// ¿Alguna computadora se llama server.reto.com?
string answerQ5(vector<Details> details) {
    bool a = false;
    for (auto detail : details) {
        if (detail.getSourceName() == "server.reto.com") {
            a = true;
        }
    }
    if (a) {
        return "Si";
    } else {
        return "No";
    }
}

// ¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)?
vector<string> answerQ6(vector<Details> details) {
    vector<string> services;
    for (auto detail : details) {
        string a = "", b = "", c = "";
        stringstream ss(detail.getDestinationName());
        getline(ss, a, '.');
        getline(ss, b, '.');
        ss >> c;
        if (c != "") {
            if (find(services.begin(), services.end(), b) != services.end()) {
                
            } else {
                services.push_back(b);
            }
        } else {
            if (find(services.begin(), services.end(), a) != services.end()) {
                
            } else {
                services.push_back(a);
            }
        }
    }
    return services;
}

// Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente.
vector<int> answerQ7(vector<Details> details) {
    vector<int> ports;
    for (auto detail : details) {
        if (find(ports.begin(), ports.end(), detail.getDestinationPort()) != ports.end()) {
            
        } else {
            ports.push_back(detail.getDestinationPort());
        }
    }
    return ports;
}

int main(int argc, const char * argv[]) {
    CSV csv = CSV("/Users/LuiggiFernandez/Desktop/LF_Coding/Projects/LF_Coding/POO_Class/POO_Class/POO/equipo4.csv");
    vector<Details> details = csv.read_csv_details();
    Filter filter = Filter(details);
//    filter.quicksort(bool (*sort)(details[0], details[details.size()]));
    cout << "¿Cuántos registros tiene tu archivo?\nRespuesta: " << answerQ1(details) << endl;
    long q1;
    string q2;
    answerQ2(details, &q1, &q2);
    cout << "¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?\nRespuesta: " << q1 << " " << q2 << endl;
    cout << "¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?\nRespuesta: ";
    for (auto i: answerQ3(details)) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "¿Cuál es la dirección de la red interna de la compañía?\nRespuesta: " << answerQ4(details) << endl;
    cout << "¿Alguna computadora se llama server.reto.com?\nRespuesta: " << answerQ5(details) << endl;
    cout << "¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)?\nRespuesta: ";
    for (auto i: answerQ6(details)) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente.\nRespuesta: ";
    for (auto i: answerQ7(details)) {
        cout << i << ' ';
    }
    cout << endl;
//    copy(details.begin(), details.end(), ostream_iterator<Details>(cout));
    return 0;
}
