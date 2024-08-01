#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int Dijstra(vector<vector<int>> &adj, int time, int change)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        vector<int> dist1(n, INT_MAX);
        q.push({0, 1});
        dist[1] = 0;
        int flag = 0;
        while (!q.empty())
        {
            auto it = q.top();
            int value = it.first;
            int node = it.second;
            q.pop();
            if (node == n - 1)
            {
                flag++;
            }
            if (flag == 2)
            {
                return value;
            }

            int temp = value / change;
            int neiVlue = value;
            if (temp & 1)
            {
                neiVlue = change * (temp + 1);
            }
            neiVlue += time;

            for (auto &&nei : adj[node])
            {
                int neiNode = nei;
                // if (neiNode == n - 1)
                // {
                //     if (dist[neiNode] > temp)
                //     {
                //         q.push({temp, neiNode});
                //         dist1[neiNode] = dist[neiNode];
                //         dist[neiNode] = temp;
                //     }
                //     else if (dist1[neiNode] > temp)
                //     {
                //         q.push({temp, neiNode});
                //         dist1[neiNode] = temp;
                //     }
                // }
                // else
                // {
                if (dist[neiNode] > neiVlue)
                {
                    q.push({neiVlue, neiNode});
                    dist1[neiNode] = dist[neiNode];
                    dist[neiNode] = neiVlue;
                }
                else if (dist1[neiNode] > neiVlue && dist[nei] != neiVlue)
                {
                    q.push({neiVlue, neiNode});
                    dist1[neiNode] = neiVlue;
                }
                // }
            }
        }
        return 0;
    }

public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &&it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = Dijstra(adj, time, change);
        return ans;
    }
};

int main()
{

    return 0;
}