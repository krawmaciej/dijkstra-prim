#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

struct Vertex
{
    int connectedTo;
    int distance;
    Vertex* next = nullptr;
};

#endif // VERTEX_H_INCLUDED
