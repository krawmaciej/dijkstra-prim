#include <iostream>
#include <vector>
#include <string>
#include "dijkstra.h"
#include "graph.h"
#include "vertex.h"
#include "row.h"
#include "prim.h"
#include "point.h"

std::vector<Point> getInput(std::istream& cin)
{
    std::vector<Point> points;
    Point point;
    unsigned int pos = 0;

    std::string s,t;
    getline(cin,s);

    while ((pos = s.find_first_of(','))!=std::string::npos)
    {
        point.x = stoi(s.substr(0,pos));
        s.erase(0,pos+1);
        if ((pos = s.find_first_of(','))==std::string::npos)
            break;
        point.y = stoi(s.substr(0,pos));
        s.erase(0,pos+1);
        points.push_back(point);
    }

    return points;
}

float** createMatrixOfCompleteGraph(std::vector<Point> points)
{
    // memory for matrix
    float** matrix = new float*[points.size()];
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        matrix[i] = new float[points.size()];
        // main diagonal is all zeros
        matrix[i][i] = 0;
    }

    for (unsigned int i = 0; i < points.size(); ++i)
        for (unsigned int j = i+1; j < points.size(); ++j)
            matrix[i][j] = matrix[j][i] =
                distanceBetweenPoints(points[i], points[j]);
}

int main()
{
    using namespace std;

    vector<Point> points = getInput(cin);

    for (unsigned int i = 0; i < points.size(); ++i)
        cout << i << ": " << points[i].x << ", " << points[i].y << endl;


    float matrix[VERTICES][VERTICES] = {
    /*     0  1  2  3  4 */
    /*0*/ {0, 4, 1, 0, 0},
    /*1*/ {4, 0, 0, 1, 9},
    /*2*/ {1, 0, 0, 7, 7}, // {1, 0, 0, 7, 6}
    /*3*/ {0, 1, 7, 0, 8}, // {0, 1, 7, 0, 14}
    /*4*/ {0, 9, 7, 8, 0}
    };

    Graph graph = createGraphFromMatrix(matrix, VERTICES);

    cout << "Graph:\n";
    printGraph(graph);

    cout << endl << endl << "Shortest path:\n";
    Graph shortestPath = dijkstra(graph, 3);
    printGraph(shortestPath);

    cout << endl << endl << "MST:\n";
    prim(graph, 3);
    Graph mst = prim(graph, 3);
    printGraph(mst);
    cout << endl;
    printTree(mst);

    deleteGraph(graph);
    deleteGraph(shortestPath);
    return 0;
}
