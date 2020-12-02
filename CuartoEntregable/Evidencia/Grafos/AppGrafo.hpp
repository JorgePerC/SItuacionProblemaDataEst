#ifndef AppGrafo_hpp
#define AppGrafo_hpp


#include "Graph.hpp"
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include <list> 

using namespace std;


template <class V, class E>
class AppGrafo{

    Graph <V,E> listaAdjacencia; 
    vector <vector <bool> > matrizAdjacencia;

public:
    AppGrafo();
    void loadGraph(int, int);
    void DFS(int N);
    void BFS(int N);
    vector<bool> conectar(int, int);

    void helperMethod(int v, bool visited[]);
};

template <class V, class E>
AppGrafo<V, E>::AppGrafo(){
}

template <class V, class E>
void AppGrafo<V, E>::loadGraph(int node, int vertex){
    //Crear la matriz de ayacencia
    for (int i = 0;  i < node; i++){
        vector<bool> vecBool;
        matrizAdjacencia.push_back(vecBool);
        for (int j = 0;  j < node; j++){
            matrizAdjacencia[i].push_back(false);
        }
    }
    // generate the random positions 
    int positions = ((node * node) - node) / 2;
    vector<bool> vec = conectar(positions, vertex);
    int counter = 0;
    for (int i = 0;  i < node; i++){
        for (int j = 0;  j < node; j++){
            if (i == j) { 

            } else {
                if (j > i) { 
                    matrizAdjacencia[i][j] = vec[counter];
                    matrizAdjacencia[j][i] = vec[counter];
                    counter ++;
                } else {

                }
            }
        }
    }

    //Llenar la lista de adyacencia
    for (int i = 0;  i < node; i++){
        listaAdjacencia.addVertex(i);
        for (int j = 0;  j < node; j++){
            if (matrizAdjacencia[i][j] == true){
                //Agregar un puente sin peso
                listaAdjacencia.addEdge(i, j, 0);
            }
            if (i==j){
                break;
            }
            
        }
    }
}

template <class V, class E>
vector<bool> AppGrafo<V, E>::conectar(int positions, int vertex){
    vector<bool> vec;
    for (int i = 0; i < positions - 1; i++) {
        if (vertex > 0) {
            vec.push_back(true);
            vertex--;
        } else {
            vec.push_back(false);
        }
    }
    for (int i = 0; i < positions - 1; i++) {
        int j = i + rand() % (positions - i);
        swap(vec[i], vec[j]);
    }
    return vec;
}

// en vex de pasar una matriz de adjacencia, ocupa la generada automáticamente
// vector <vector <bool>>
template <class V, class E>
void AppGrafo<V,E>::BFS(int N) {
    list<int> Q;
    
    bool *visitedNodes = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visitedNodes[i] = false; 
  
    // Marcar el nodo inicial com pasado
    visitedNodes[N] = true; 
    Q.push_back(N); 
   
    list<int>::iterator i; 
  
    while(!Q.empty()){ 
        // Dequeue a vertex from queue and print it 
        N = Q.front(); 
        cout << N << " "; 
        Q.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = matrizAdjacencia.nodes[N].begin(); i != matrizAdjacencia.nodes[N].end(); ++i){ 
            if (!visitedNodes[*i]){ 
                visitedNodes[*i] = true; 
                Q.push_back(*i); 
            } 
        } 
    } 
}

template <class V, class E>
void AppGrafo<V, E>::helperMethod(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = listaAdjacencia.nodes[v].begin(); i != listaAdjacencia.nodes[v].end(); ++i)
        if (!visited[*i])
            helperMethod(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive helperMethod()
template <class V, class E>
void AppGrafo<V, E>::DFS(int v)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < v; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    helperMethod(v, visited);
}

#endif