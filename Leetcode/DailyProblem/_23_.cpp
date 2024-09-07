#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        vector<vector<pair<int, int>>> adj(n);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, tuple<long long, long long, long long>>, vector<pair<long long, tuple<long long, long long, long long>>>, greater<>> pq;
        pq.push({0, {source, -1, -1}});
        vector<long long> v(n, 2 * 1e9);
        v[source] = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            long long wt = it.first;
            long long node = get<0>(it.second);
            long long fir = get<1>(it.second);
            long long sec = get<2>(it.second);

            if (node == destination)
            {
                if (wt > target || (wt < target && fir == -1))
                {
                    return {};
                }
                else if (wt < target && fir != -1)
                {
                    for (int i = 0; i < m; i++)
                    {
                        int u = edges[i][0];
                        int v = edges[i][1];
                        int w = edges[i][2];
                        if (w < 0)
                        {
                            edges[i][2] = 1;
                            if ((u == fir || v == fir) && (v == sec || u == sec))
                            {
                                edges[i][2] = target - wt + 1;
                            }
                        }
                    }
                    return edges;
                }
                else if (wt == target && fir == -1)
                {
                    for (int i = 0; i < m; i++)
                    {
                        int u = edges[i][0];
                        int v = edges[i][1];
                        int w = edges[i][2];
                        if (w < 0)
                        {
                            edges[i][2] = 2 * 1e9;
                        }
                    }
                    return edges;
                }
                else
                {
                    for (int i = 0; i < m; i++)
                    {
                        int u = edges[i][0];
                        int v = edges[i][1];
                        int w = edges[i][2];
                        if (w < 0)
                        {
                            edges[i][2] = 1;
                        }
                    }
                    return edges;
                }
            }

            for (int i = 0; i < adj[node].size(); i++)
            {
                int neii = adj[node][i].first;
                int dist = abs( adj[node][i].second);
                int temp1 = fir;
                int temp2 = sec;

                if (neii != node && wt + dist < v[neii])
                {
                    if (temp1 == -1 &&  adj[node][i].second < 0)
                    {
                        temp1 = node;
                        temp2 = neii;
                    }
                    v[neii] = wt + dist;
                    pq.push({wt + dist, {neii, temp1, temp2}});
                }
            }
            // for (auto &&nei : adj[node])
            // {
            //     int neii = nei.first;
            //     int dist = abs(nei.second);
            //     int temp1 = fir;
            //     int temp2 = sec;

            //     if (neii != node && wt + dist < v[neii])
            //     {
            //         if (temp1 == -1 && nei.second < 0)
            //         {
            //             temp1 = node;
            //             temp2 = neii;
            //         }
            //         v[neii] = wt + dist;
            //         pq.push({wt + dist, {neii, temp1, temp2}});
            //     }
            // }
        }
        return {};
    }
};

int32_t main()
{
    return 0;
}
