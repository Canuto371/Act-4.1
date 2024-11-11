#include "grafo.cpp"
#include <iostream>
#include <limits>
using namespace std;

int main() {

    int n, m;
        // Solicitar el número de vértices
        while (true) {
            cout << "Ingrese el número de vértices: ";
            cin >> n;

            if (cin.fail() || n <= 0) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
                cerr << "Error: Entrada no válida. Asegúrese de que el número de vértices sea positivo." << endl;
            } else {
                break; // Salir del bucle si la entrada es válida
            }
        }

        // Solicitar el número de arcos
        while (true) {
            cout << "Ingrese el número de arcos: ";
            cin >> m;

            if (cin.fail() || m < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Entrada no válida. Asegúrese de que el número de arcos no sea negativo." << endl;
            } else {
                break; // Salir del bucle si la entrada es válida
            }
        }

    Grafo grafo(n, m);

    vector<vector<int>> matrizAdyacencia;
    vector<vector<int>> listaAdyacencia;

    grafo.loadGraph(matrizAdyacencia, listaAdyacencia);

    // DFS
    int nodoInicialDFS;
    cout << "Ingrese el nodo inicial para DFS (0 a " << n - 1 << "): ";

    while (!(cin >> nodoInicialDFS) || nodoInicialDFS < 0 || nodoInicialDFS >= n) {
        cout << "Error: El nodo inicial debe ser un número entero en el rango de 0 a " << n - 1 << ". Inténtelo de nuevo: ";
        cin.clear(); // Limpiar el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
    }
    // Ejecutar DFS solo si el nodo inicial es válido
    grafo.DFS(matrizAdyacencia, nodoInicialDFS);

    int nodoInicialBFS;
    cout << "Ingrese el nodo inicial para BFS (0 a " << n - 1 << "): ";
    
    while (!(cin >> nodoInicialBFS) || nodoInicialBFS < 0 || nodoInicialBFS >= n) {
        cout << "Error: El nodo inicial debe ser un número entero en el rango de 0 a " << n - 1 << ". Inténtelo de nuevo: ";
        cin.clear(); // Limpiar el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
    }
    // Ejecutar BFS solo si el nodo inicial es válido
    grafo.BFS(listaAdyacencia, nodoInicialBFS);

    return 0;
}
