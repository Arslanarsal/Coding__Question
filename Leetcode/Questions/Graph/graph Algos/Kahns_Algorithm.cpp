#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(V+E)
    Space complexity: O(V)

    Where V is the number of vertices and E is the number of edges.
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Creating adjacency list.
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    // Calculaing indegree of each vertex.
    vector<int> indegree(v);
    for (auto edge : edges)
    {
        indegree[edge[1]]++;
    }
    // Push all vertices of indegree 0 in queue.
    queue<int> que;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    vector<int> result; // It will store topological sort of the given graph.
    // Finding topologial sorting
    while (!que.empty())
    {
        int src = que.front();
        que.pop();
        result.push_back(src);
        for (int node : adj[src])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                que.push(node);
            }
        }
    }
    return result;
}

int main()
{
    int vertices = 6; // Example number of vertices
    int edges = 6;    // Example number of edges

    // Example edges represented as pairs of vertices
    vector<vector<int>> edgeList = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologicalSort(edgeList, vertices, edges);

    cout << "Topological Sorting Order: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}