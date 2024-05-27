#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int time = 1;
    void dfs(int node, int parent, int tim[], int low[], vector<int> &vis, vector<vector<int>> &ans, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        tim[node] = low[node] = time;
        time++;
        for (auto &&it : adj[node])
        {
            if (it == parent)
                continue;

            if (vis[it] == 0)
            {
                dfs(it, node, tim, low, vis, ans, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] > tim[node])
                {
                    ans.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &&it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int tim[n];
        int low[n];
        vector<vector<int>> ans;
        dfs(0, -1, tim, low, vis, ans, adj);
        return ans;
    }
};

int main()
{

    return 0;
}