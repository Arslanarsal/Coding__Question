#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto edge : times)
        {
            graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto neighbor : graph[u])
            {
                int v = neighbor.first;  // node
                int w = neighbor.second; // distance

                if (distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (distance[i] == INT_MAX)
                return -1;

            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};

int main()
{

    return 0;
}