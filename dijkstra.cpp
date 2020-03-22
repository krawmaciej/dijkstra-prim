#include <queue>
#include <vector>
#include "graph.h"
#include "row.h"
#include "vertex.h"
#include "dijkstra.h"

void dijkstra(const Graph* graph)
{
    std::priority_queue<Row*, std::vector<Row*>, CustomCompare> pq;

    Row* row1 = new Row;
    Row* row2 = new Row;

    row1->vertex = new Vertex;
    row1->distance = 5;
    row1->previous = 1;

    row2->vertex = new Vertex;
    row2->distance = 2;
    row2->previous = 1;

    pq.push(row1);
    pq.push(row2);

    std::cout << pq.top()->distance;





}
