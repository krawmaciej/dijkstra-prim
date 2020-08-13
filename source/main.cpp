#include <iostream>
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

float** createMatrixOfCompleteGraph(const std::vector<Point>& points)
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

    return matrix;
}

void freeMemoryOfMatrix(float** matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main()
{
    using namespace std;

    cout << "Input: ";
    vector<Point> points = getInput(cin);

    for (unsigned int i = 0; i < points.size(); ++i)
        cout << i << ": " << points[i].x << ", " << points[i].y << endl;


    float** matrix = createMatrixOfCompleteGraph(points);
/*
//  PRINT MATRIX
    cout << "graph size: " << points.size() << endl;
    for (int i = 0; i < points.size(); ++i)
    {
        for (int j = 0; j < points.size(); ++j)
            cout << test[i][j] << ' ';
        cout << endl;
    }
*/

    Graph graph = createGraphFromMatrix(matrix, points.size());

    cout << "Graph:\n";
    printGraph(graph);

    cout << "Starting vertex: ";
    int startingVertex = 0;
    cin >> startingVertex;

    cout << endl << endl << "Shortest path:\n";
    Graph shortestPath = dijkstra(graph, startingVertex);
    printGraph(shortestPath);

    cout << endl << "Shortest path tree: " << shortestPath.tree;

    cout << endl << endl << "MST:\n";
    Graph mst = prim(graph, startingVertex);
    printGraph(mst);
    cout << endl << "MSTree: " << mst.tree;

    deleteGraph(graph);
    deleteGraph(shortestPath);
    deleteGraph(mst);
    freeMemoryOfMatrix(matrix, points.size());
    return 0;
}
