#include <queue>
#include <vector>
#include <iostream>
#include "graph.h"
#include "row.h"
#include "vertex.h"
#include "dijkstra.h"

Graph dijkstra(const Graph& graph, int startingVertex, bool prim)
{
    // initialize shortest path graph (tree)
    Graph shortestPathGraph;
    // graph will have same number of vertices as graph it's created from
    shortestPathGraph.size = graph.size;
    shortestPathGraph.vertices = new Vertex*[graph.size];
    // at first there are no vertices connected to a vertex
    // it is needed because each vertex is points to other,
    // and when there are no more vertices it points to null
    for (int i = 0; i < graph.size; ++i) shortestPathGraph.vertices[i] = nullptr;

    // an array to hold algorithm's table
    Row* table = new Row[graph.size];
    Vertex** vertices = graph.vertices;

    // Distance to starting vertex is 0 and it's visited
    table[startingVertex].distance = 0;
    table[startingVertex].visited = true;
    int visitedSize = 1;

    //int processedVertex = startingVertex; or processedVertex = lowestDistance(tab, graph.size);

    for (int processedVertex = startingVertex;
            visitedSize < graph.size; ++visitedSize)
    {
        updateDistances(table, vertices, processedVertex, prim);
        processedVertex = findLowestDistance(table, graph.size);
        table[processedVertex].visited = true;

        // connect previous vertex with vertex with current lowest distance
        int previous = table[processedVertex].previous;
        int distanceBetween = table[processedVertex].distance - (int(!prim) * table[previous].distance);
        connectVertex(shortestPathGraph.vertices[processedVertex], previous, distanceBetween);
        connectVertex(shortestPathGraph.vertices[previous], processedVertex, distanceBetween);
    }

    return shortestPathGraph;
}

void updateDistances(Row* table, Vertex** vertices, int processedVertex, bool prim)
{
    for (Vertex* vertex = vertices[processedVertex];
             vertex; vertex = vertex->next)
    {
        Row &adjVertexRow = table[vertex->connectedTo];

        if (adjVertexRow.visited)
            continue;

        int newDistance =
            (int(!prim) * table[processedVertex].distance) + vertex->distance;

        if (adjVertexRow.distance > newDistance)
        {
            adjVertexRow.distance = newDistance;
            adjVertexRow.previous = processedVertex;
        }
    }

}

int findLowestDistance(Row* tab, int size)
{
    int lowest = 0;
    // find first not visited vertex's index
    for (int i = 0; i < size; ++i)
        if (!tab[i].visited)
            lowest = i;

    for (int i = 0; i < size; ++i)
        if (!tab[i].visited
            && (tab[i].distance < tab[lowest].distance))
            lowest = i;

    return lowest;
}




