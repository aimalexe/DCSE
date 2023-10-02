/*
Implement graphs with the following operations
a) Graph Creation
b) Adding Vertex to Graph
c) Removal of Vertex from the graph
d) Checking whether an edge exist between two vertices
e) Printing graph
*/

#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

class Graph
{
private:
    bool adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Graph() : numVertices(0)
    {
        for (int i = 0; i < MAX_VERTICES; i++)
            for (int j = 0; j < MAX_VERTICES; j++)
                adjacencyMatrix[i][j] = false;
    }

    void addVertex(int vertex)
    {
        if (vertex >= 0 && vertex < MAX_VERTICES && numVertices < MAX_VERTICES)
            numVertices++;
    }

    void removeVertex(int vertex)
    {
        if (vertex >= 0 && vertex < MAX_VERTICES)
        {
            for (int i = 0; i < MAX_VERTICES; i++)
            {
                adjacencyMatrix[vertex][i] = false;
                adjacencyMatrix[i][vertex] = false;
            }
            numVertices--;
        }
    }

    void addEdge(int source, int destination)
    {
        if (source >= 0 && source < MAX_VERTICES && destination >= 0 && destination < MAX_VERTICES)
            adjacencyMatrix[source][destination] = true;
    }

    void removeEdge(int source, int destination)
    {
        if (source >= 0 && source < MAX_VERTICES && destination >= 0 && destination < MAX_VERTICES)
            adjacencyMatrix[source][destination] = false;
    }

    bool hasEdge(int source, int destination)
    {
        if (source >= 0 && source < MAX_VERTICES && destination >= 0 && destination < MAX_VERTICES)
            return adjacencyMatrix[source][destination];
        return false;
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << " is connected to: ";
            for (int j = 0; j < numVertices; j++)
                if (adjacencyMatrix[i][j])
                    cout << j << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    graph.printGraph();

    cout << "\nDoes edge (1, 2) exist? " << (graph.hasEdge(1, 2) ? "Yes" : "No") << endl;
    cout << "Does edge (2, 3) exist? " << (graph.hasEdge(2, 3) ? "Yes" : "No") << endl;
    cout << "Does edge (1, 4) exist? " << (graph.hasEdge(1, 4) ? "Yes" : "No") << endl;

    graph.removeVertex(3);

    cout << "Graph after removing vertex 3:" << endl;
    graph.printGraph();

    return 0;
}
