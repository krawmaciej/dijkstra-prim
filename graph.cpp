#include <iostream>
#include "graph.h"

void connectOneVertex(Vertex* &vertex, int connectedTo, float distance)
{
    Vertex* newVertex = new Vertex;
    newVertex->connectedTo = connectedTo;
    newVertex->distance = distance;
    newVertex->next = vertex;

    vertex = newVertex;
}

void connectVertex(Graph& graph, int from, int to, float distance)
{
    connectOneVertex(graph.vertices[from], to, distance);
    connectOneVertex(graph.vertices[to], from, distance);
    graph.tree+= std::to_string(from) + "-" + std::to_string(to) + ",";
}

Graph createGraphFromMatrix(float** matrix, int n)
{
    Graph graph;
    // table of vertices connected to vertices
    graph.vertices = new Vertex*[n];
    // at first there are no vertices connected to a vertex
    for (int i = 0; i < n; ++i) graph.vertices[i] = nullptr;
    graph.size = n;

    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (matrix[i][j])
                connectVertex(graph, i, j, matrix[i][j]);

    return graph;
}

void deleteGraph(Graph& graph)
{
    Vertex** vertices = graph.vertices;
    for (int i = 0; i < graph.size; ++i)
        deleteVertices(vertices[i]);
    delete[] vertices;
}

void deleteVertices(Vertex* vertex)
{
    Vertex* tmp;
    while (vertex)
    {
        tmp = vertex;
        vertex = vertex->next;
        delete tmp;
    }
}

void printGraph(const Graph& graph)
{
    using std::cout;
    using std::endl;

    Vertex* vertex;
    for (int i = 0; i < graph.size; ++i)
    {
        vertex = graph.vertices[i];
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
