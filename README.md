# Comparing Dijkstra's and Prim's algorithms
## Course project assignment
**Project summary:** ProjectA.pdf

### Sample inputs:
Input: ``` 1,1,0,0,1,0, ``` Starting vertex: ``` 0 ```
Input: ``` 11,11,9,22,4,29,20,30,25,50,52,52,39,67,50,26,43,42, ``` Starting vertex: ``` 4 ```
Input: ``` 1,0,2,4,0,0,4,5, ``` Starting vertex: ``` 3 ```

### How to:
Program accepts input: ``` 1,0,2,4,0,0,4,5, ``` where each pair of numbers (each number must be followed by ``` , ```) is a point on a plane. This example translates into 4 points, 0 - (1,0), 1 - (2,4), 2 - (0,0) and 3 - (5,1).

Program makes a complete graph from these points and displays graph as connections between vertices with their corresponding distances; e.g. ``` 0->(3,5.83095) (2,1) (1,4.12311) ``` which means that vertex 0 is connected to vertices: 3, 2 and 1 with distances respectively: 5.83095, 1 and 4.12311

After inputting starting vertex e.g. ``` 3 ```, program diplays graphs for **shortest path** and **minimal spanning tree**, in the same format as complete graph.
It also outputs results in a shorter form:
``` Shortest path tree: 1-3,0-3,2-3, ``` meaning vertex 1 connects to 3, 0 to 3 and 2 to 3,
``` MSTree: 1-3,0-1,2-0, ``` meaning vertex 1 connects to 3, 0 to 1 and 2 to 0.
