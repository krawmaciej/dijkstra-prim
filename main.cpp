#include <iostream>
#include "dijkstra.h"
#include "graph.h"
#include "vertex.h"
#include "row.h"
#include "prim.h"

int main()
{
    using namespace std;

//    const int INFINITY = INT_MAX/2;

    int matrix[VERTICES][VERTICES] = {
    /*     0  1  2  3  4 */
    /*0*/ {0, 4, 1, 0, 0},
    /*1*/ {4, 0, 0, 1, 9},
    /*2*/ {1, 0, 0, 7, 7}, // {1, 0, 0, 7, 6}
    /*3*/ {0, 1, 7, 0, 8}, // {0, 1, 7, 0, 14}
    /*4*/ {0, 9, 7, 8, 0}
    };

    Graph graph = createGraphFromMatrix(matrix, VERTICES);

    cout << "Graph:\n";
    printGraph(graph);

    cout << endl << endl << "Shortest path:\n";
    Graph shortestPath = dijkstra(graph, 3);
    printGraph(shortestPath);

    cout << endl << endl << "MST:\n";
    prim(graph, 3);
    Graph mst = prim(graph, 3);
    printGraph(mst);
    cout << endl;
    printTree(mst);

    deleteGraph(graph);
    deleteGraph(shortestPath);
    return 0;
}
