#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED
#include <queue>
#include <vector>
#include "graph.h"
#include "row.h"
#include "vertex.h"
#include "dijkstra.h"

/*
struct CustomCompare
{
    bool operator()(const Row* left, const Row* right)
    {
        return left->distance > right->distance;
    }
};
*/

Graph prim(const Graph& graph, int startingVertex);

#endif // PRIM_H_INCLUDED

