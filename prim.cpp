#include <queue>
#include <vector>
#include <iostream>
#include "graph.h"
#include "row.h"
#include "vertex.h"
#include "prim.h"

Graph prim(const Graph& graph, int startingVertex)
{
    return dijkstra(graph, startingVertex, true);
}



