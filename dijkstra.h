#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include <queue>
#include <vector>
#include "graph.h"
#include "row.h"
#include "vertex.h"

struct CustomCompare
{
    bool operator()(const Row* left, const Row* right)
    {
        return left->distance > right->distance;
    }
};

void dijkstra(const Graph* graph);


#endif // DIJKSTRA_H_INCLUDED
