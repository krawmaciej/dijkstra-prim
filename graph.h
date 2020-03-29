#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <string>
#include <iostream>
#include "vertex.h"

struct Graph
{
    Vertex** vertices = nullptr;
    int size = 0;
    std::string tree = "";
};

void connectOneVertex(Vertex*& vertex, int connectedTo, float distance);
void connectVertex(Graph& graph, int from, int to, float distance);
Graph createGraphFromMatrix(float** matrix, int n);
void deleteGraph(Graph& graph);
void deleteVertices(Vertex* vertex);
void printGraph(const Graph& graph);

#endif // GRAPH_H_INCLUDED






