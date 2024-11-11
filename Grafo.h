#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Grafo {
private:
    int n; // Número de vértices
    int m; // Número de arcos
    vector<vector<int>> adjMatrix; // Matriz de Adyacencia
    vector<vector<int>> adjList;   // Lista de Adyacencia

public:
    // Constructor
    Grafo(int n, int m);
    void loadGraph(std::vector<std::vector<int>>& matrizAdyacencia, std::vector<std::vector<int>>& listaAdyacencia);
    void DFS(const std::vector<std::vector<int>>& matrizAdyacencia, int nodoInicialDFS);
    void BFS(const std::vector<std::vector<int>>& listaAdyacencia, int nodoInicialBFS);
};

#endif