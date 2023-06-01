#include "./Graph.hpp"
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph(int edges, int vertices) : edges(edges), vertices(vertices) {}

void Graph::inputGraph() {
    adjacencyMatrix = matrix(vertices, array(vertices, 0));
    for(int i = 0; i < edges; ++i) {
        int vertice1, vertice2;
        std::cout << "\tinput vertice-1 and vertice-2" << std::endl << "\t";
        std::cin >> vertice1 >> vertice2;
        adjacencyMatrix[vertice1][vertice2] = 1;
        adjacencyMatrix[vertice2][vertice1] = 1;
    }
}

void Graph::printGraph() {
    std::cout << std::endl;
    for(int i = 0; i < this->vertices; ++i) {
        for(int j = 0; j < this->vertices; ++j) {
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int Graph::getCountOfInd() {
    int n = vertices;
    int maxSize = 0;
    array set;
    for(int i = 0; i < n; ++i) {
        set.push_back(i);
    }
    for (int i = 0; i < (1 << n); i++) {
        array subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(set[j]);
            }
        }
        if (isIndipendent(subset)) {
            if (subset.size() > maxSize) {
                maxSize = subset.size();
            }
        }
    }
    
    return maxSize;
}

bool Graph::isIndipendent(array& set) {
    for (int i = 0; set.size() !=0 &&  i < set.size() - 1; ++i) {
        if (adjacencyMatrix[set[i]][set[i+1]] == 1)
            return false;
    }
    return true;
}