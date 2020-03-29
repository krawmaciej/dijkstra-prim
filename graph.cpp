#include <iostream>
#include "graph.h"

void connectVertex(Vertex* &vertex, int connectedTo, float distance)
{
    Vertex* newVertex = new Vertex;
    newVertex->connectedTo = connectedTo;
    newVertex->distance = distance;
    newVertex->next = vertex;

    vertex = newVertex;
}

Graph createGraphFromMatrix(const float matrix[][GRAPH_VERTICES], int n)
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

void printTree(const Graph& graph)
{
    using std::cout;

    // initialize visited table with false
    bool* visited = new bool[graph.size] {false};
    int countVisited = 0;

    for (int i = 0; countVisited < graph.size; ++i)
    {
        //cout << "i: " << i << std::endl;
        //cout << "visited: " << countVisited << std::endl;
        Vertex* vertex = graph.vertices[i];
        // if vertex wasn't visited yet
        if (!visited[i])
        {
            visited[i] = true;
            ++countVisited;
        }

        while (vertex)
        {
            // if vertex wasn't visited yet
            if (!visited[vertex->connectedTo])
            {
                cout << i << "-" << vertex->connectedTo << ",";
                visited[vertex->connectedTo] = true;
                ++countVisited;
            }
            vertex = vertex->next;
        }
    }
}
