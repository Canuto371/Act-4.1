#include "Grafo.h"
#include <iostream>
#include <vector>
#include <functional> 
#include <algorithm>
#include <sstream>

using namespace std;

// Constructor de la clase Grafo
Grafo::Grafo(int n, int m) : n(n), m(m) {
    adjMatrix.assign(n, vector<int>(n, 0));  // Inicializar la matriz de adyacencia con 0
    adjList.assign(n, vector<int>());
}

// Función que carga los arcos del grafo y los almacena en una Matriz de Adjacencia y en una Lista de Adjacencia.
/*
Acepta de entrada:
    Dos enteros positivos:
    - n (Cantidad de Vertices)
    - m (Cantidad de Arcos)

    - La Matriz de Adjacencia (parámetro por ref)
    - La Lista de Adjacencia (parámetro por ref)
*/ 
void Grafo::loadGraph(std::vector<std::vector<int>>& matrizAdyacencia, std::vector<std::vector<int>>& listaAdyacencia) {
    matrizAdyacencia.assign(n, vector<int>(n, 0));
    listaAdyacencia.assign(n, vector<int>());

    cout << "Introduce los " << m << " arcos en formato (u, v) donde u y v son los vértices (ingresar u y v separados por un espacio):" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Iterar sobre los m arcos
    for (int i = 0; i < m; ++i) {
        try {
            string input;

            cin.clear(); // Limpiar los flags de error
            
            cout << "Ingrese el arco " << i + 1 << ": ";
            getline(cin, input);  // Leer toda la línea para asegurar un formato correcto

            // Verificar que la entrada contenga dos números separados por un espacio
            istringstream iss(input);
            int u, v;
            
            if (!(iss >> u >> v) || !(iss >> ws).eof()) {
                throw invalid_argument("Entrada inválida. Por favor, ingrese solo dos números enteros positivos separados por un espacio.");
            }

            // Verificar que los números están dentro del rango válido
            if (u < 0 || u >= n || v < 0 || v >= n) {
                throw out_of_range("Error: el vértice u o v está fuera de rango.");
            }

            // Agregar arco en la matriz de adyacencia
            matrizAdyacencia[u][v] = 1;
            matrizAdyacencia[v][u] = 1; 

            // Agregar arco en la lista de adyacencia
            listaAdyacencia[u].push_back(v);
            listaAdyacencia[v].push_back(u); 

        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
            --i;  // Repetir la entrada actual
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
            --i;  // Repetir la entrada actual
        }
    }
}

// Función que imprime el recorrido DFS (profundidad) a partir del nodo incial (nodoInicialDFS). 
// Acepta de entrada la Matriz de Adjacencia y un entero representado el nodo incial.
void Grafo::DFS(const std::vector<vector<int>>& matrizAdyacencia, int nodoInicialDFS) {
    // Inicializar el vector de visitados con "false" para cada vértice
    vector<bool> visitados(n, false);

    function<void(int)> dfs_recursivo = [&](int nodo) {
        visitados[nodo] = true; // Marcar el nodo como visitado
        cout << nodo << " ";

        // Recorrer todos los vecinos del nodo
        for (int vecino = 0; vecino < n; ++vecino) {
            // Si el vecino está conectado y no ha sido visitado, llamar recursivamente a DFS
            if (matrizAdyacencia[nodo][vecino] == 1 && !visitados[vecino]) {
                dfs_recursivo(vecino);
            }
        }
    };

    cout << "DFS: ";
    dfs_recursivo(nodoInicialDFS);
    cout << endl;
}

// Función que imprime el recorrido BFS (anchura) a partir del nodo incial (nodoInicialBFS). 
// Acepta de entrada la Lista de Adjacencia y un entero representado el nodo incial.
void Grafo::BFS(const std::vector<vector<int>>& listaAdyacencia, int nodoInicialBFS) {
    // Inicializar el vector de visitados con "false" para cada vértice
    vector<bool> visitados(n, false);
    queue<int> cola;  // Cola para almacenar los nodos pendientes por visitar

    cola.push(nodoInicialBFS);
    visitados[nodoInicialBFS] = true;  // Marcar el nodo inicial como visitado

    cout << "BFS: ";
    while (!cola.empty()) {
        int nodo = cola.front();
        cola.pop();  // Eliminar el nodo de la cola
        cout << nodo << " ";

        // Recorrer todos los vecinos del nodo
        for (int vecino : listaAdyacencia[nodo]) {
            // Si el vecino no ha sido visitado, marcarlo y agregarlo a la cola
            if (!visitados[vecino]) {
            if (!visitados[vecino]) {
                visitados[vecino] = true;
                cola.push(vecino);
            }
        }
    }
    cout << endl;
}
