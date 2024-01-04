#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &visited, vector<int> &dfsvisited, vector<vector<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, visited, dfsvisited, adj))
            {
                return true;
            }
        }
        if (dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    vector<int> visited(n + 1, 0);
    vector<int> dfsvisited(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, dfsvisited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}