#include <bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> vist(n + 1, 0);
    vist[0] = 1;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    priority_queue<pair<int, pair<int, int>>> pq; // {dist , {node , parent}}
    pq.push({0, {0, -1}});
    int ans = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dist = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        if (!vist[node])
        {
            ans += dist;
            for (auto &&neighbour : adj[node])
            {
                if (vist[neighbour])
                {
                    /* code */
                }
                
            }
        }
    }
}

int main()
{

    return 0;
}