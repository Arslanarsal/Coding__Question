#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto &&it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, INT_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)1e9 + 7;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.first;
            int dis = it.second;
            for (auto &&ni : adj[node])
            {
                int newnode = it.first;
                int newdis = it.second;
                if (dis + newdis < dist[newnode])
                {
                    dist[newnode] = dis + newdis;
                    ways[newnode] = ways[node];
                    pq.push({dist[newnode], newnode});
                }
                else if (dis + newdis == dist[newnode])
                {
                    ways[newnode] = ways[newnode] + ways[node] % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

int main()
{

    return 0;
}