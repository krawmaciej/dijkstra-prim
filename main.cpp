#include <iostream>
#include "dijkstra.h"
#include "graph.h"
#include "vertex.h"
#include "row.h"

int main()
{
    using namespace std;

    const int VERTICES = 3;

    int matrix[VERTICES][VERTICES] = {
    /*     0  1  2*/
    /*0*/ {0, 3, 5},
    /*1*/ {3, 0, 0},
    /*2*/ {5, 0, 0}
    };


    Graph graph = createGraphFromMatrix(matrix, VERTICES);

    dijkstra(&graph);

    cout << endl;

    printGraph(&graph);

    return 0;
}
