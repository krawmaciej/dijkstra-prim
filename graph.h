#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <string>
#include <iostream>
#include "vertex.h"

#define GRAPH_VERTICES 3

struct Graph
{
    Vertex** vertices = nullptr;
    int size = 0;
};

void connectVertex(Vertex*& vertex, int connectedTo, float distance);
Graph createGraphFromMatrix(const float matrix[][GRAPH_VERTICES], int n);
void deleteGraph(Graph& graph);
void deleteVertices(Vertex* vertex);
void printGraph(const Graph& graph);
void printTree(const Graph& graph);

#endif // GRAPH_H_INCLUDED






