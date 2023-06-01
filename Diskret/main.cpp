#include <iostream>
#include "./Graph/Graph.hpp"

int main() {
    int vertices = 0, edges = 0;

    std::cout << "set count of vertices of the graph :: ";
    std::cin >> vertices;

    std::cout << "set count of edges of the graph :: ";
    std::cin >> edges;

    Graph newGraph = Graph(edges, vertices);

    newGraph.inputGraph();
    newGraph.printGraph();

    std::cout << std::endl << "\t" << "The independence number of a graph is " << newGraph.getCountOfInd() << std::endl;

    system("pause");
    return 0;
}
