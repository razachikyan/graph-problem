#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using array = std::vector<int>;
using matrix = std::vector<std::vector<int>>;

class Graph {
    public:
        Graph(int edges, int vertices);
        void printGraph();
        void inputGraph();
        int getCountOfInd();
        bool isIndipendent(array& set);
    private:
        matrix adjacencyMatrix;
        int edges;
        int vertices;
};

#endif