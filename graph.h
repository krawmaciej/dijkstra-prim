#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <string>
#include <iostream>
#include "vertex.h"

struct Graph
{
    Vertex** vertices = nullptr;
    int size = 0;
};

void connectVertex(Vertex*& vertex, int connectedTo, int distance);
Graph createGraphFromMatrix(const int matrix[][5], int n);
void deleteGraph(Graph& graph);
void deleteVertices(Vertex* vertex);
void printGraph(const Graph& graph);

#endif // GRAPH_H_INCLUDED






