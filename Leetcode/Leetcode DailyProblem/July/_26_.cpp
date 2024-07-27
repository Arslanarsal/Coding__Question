#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
    int solve(int n, vector<vector<pair<int, int>>> &adj, int i, int distanceThreshold)
    {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        q.push({0, i});

        while (!q.empty())
        {
            int val = q.top().first;
            int node = q.top().second;
            q.pop();

            if (val > dist[node])
                continue;

            for (auto &it : adj[node])
            {
                int newnode = it.first;
                int newval = it.second;

                if (val + newval <= distanceThreshold && val + newval < dist[newnode])
                {
                    dist[newnode] = val + newval;
                    q.push({dist[newnode], newnode});
                }
            }
        }

        for (int d : dist)
        {
            if (d <= distanceThreshold)
            {
                ans++;
            }
        }

        return ans - 1; // Subtract 1 to exclude the city itself
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int ans = 0;
        int minval = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int reach = solve(n, adj, i, distanceThreshold);
            if (reach < minval || (reach == minval && i > ans))
            {
                ans = i;
                minval = reach;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> edges =

        {{0, 1, 10},
         {0, 2, 1},
         {2, 3, 1},
         {1, 3, 1},
         {1, 4, 1},
         {4, 5, 10}};

    Solution sol;
    sol.findTheCity(6, edges, 20);

    return 0;
}