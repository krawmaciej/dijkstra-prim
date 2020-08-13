#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include <queue>
#include <vector>
#include "graph.h"
#include "row.h"
#include "vertex.h"

/*
struct CustomCompare
{
    bool operator()(const Row* left, const Row* right)
    {
        return left->distance > right->distance;
    }
};
*/

Graph dijkstra(const Graph& graph, int startingVertex, bool prim = false);
void updateDistances(Row* table, Vertex** vertices, int processedVertex, bool prim = false);
int findLowestDistance(Row* tab, int size);



#endif // DIJKSTRA_H_INCLUDED
