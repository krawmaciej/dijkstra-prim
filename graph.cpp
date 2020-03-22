#include <iostream>
#include "graph.h"

Graph createGraphFromMatrix(const int matrix[][3], int n)
{
    Graph graph;
    // table of vertices connected to vertices
    graph.vertices = new Vertex*[n];
    // at first there are no vertices connected to a vertex
    for (int i = 0; i < n; ++i) graph.vertices[i] = nullptr;
    graph.size = n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j])
                connectVertex(graph.vertices[i], j, matrix[i][j]);

    return graph;
}

void connectVertex(Vertex* &vertex, int connectedTo, int distance)
{
    Vertex* newVertex = new Vertex;
    newVertex->connectedTo = connectedTo;
    newVertex->distance = distance;
    newVertex->next = vertex;

    vertex = newVertex;
}

void printGraph(const Graph* graph)
{
    using std::cout;
    using std::endl;

    Vertex* vertex;
    for (int i = 0; i < graph->size; ++i)
    {
        vertex = graph->vertices[i];
        cout << i << "->";
        while (vertex)
        {
            cout << "(" << vertex->connectedTo
                 << "," << vertex->distance << ") ";
            vertex = vertex->next;
        }
        cout << endl;
    }
}
