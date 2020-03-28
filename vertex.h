#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

struct Vertex
{
    int connectedTo;
    float distance;
    Vertex* next = nullptr;
};

#endif // VERTEX_H_INCLUDED
