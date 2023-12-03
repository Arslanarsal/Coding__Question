#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> ans(n, -1);
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = 1;
    ans[src] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();

        for (auto &neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push({neighbour, dis + 1});
                visited[neighbour] = 1;
                ans[neighbour] = dis + 1;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}
