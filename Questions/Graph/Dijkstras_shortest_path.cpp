#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> ans(vertices, INT_MAX);
    ans[source] = 0;
    // priority_queue<DataType, ContainerType, ComparisonFunction> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto &&neighbour : adj[node])
        {
            int newnode = neighbour.first;
            int newdist = neighbour.second;
            if (dist + newdist < ans[newnode])
            {
                ans[newnode] = dist + newdist;
                pq.push({(dist + newdist), newnode});
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}