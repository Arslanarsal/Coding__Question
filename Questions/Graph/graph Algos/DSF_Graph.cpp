#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int vistedNode[] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};
// For matric
int DFS(int i)
{
    cout << i << " ";
    vistedNode[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !vistedNode[j])
        {
            DFS(j);
        }
    }
}

/*
    Time Complexity     :   O((V * log(V)) + E)
    Space Complexity    :   O(V + E)

    Where 'V' is the number of vertex and 'E' is the number of edges in graph.
*/

void depthFirstSearchHelper(int vertex, vector<int> &visited, vector<int> &singleComponent, vector<vector<int>> &graph)
{
    visited[vertex] = 1;
    singleComponent.push_back(vertex);

    for (auto child : graph[vertex])
    {
        // Check if the node is visited before or not.
        if (!visited[child])
        {
            depthFirstSearchHelper(child, visited, singleComponent, graph);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Creating Adjacency Matrix.
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        a = edges[i][0];
        b = edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> components;
    vector<int> visited(V, 0);

    for (int vertex = 0; vertex < V; vertex++)
    {
        if (!visited[vertex])
        {
            vector<int> singleComponent;
            depthFirstSearchHelper(vertex, visited, singleComponent, graph);
            components.push_back(singleComponent);
        }
    }
    return components;
}

int main()
{
    DFS(0);

    return 0;
}