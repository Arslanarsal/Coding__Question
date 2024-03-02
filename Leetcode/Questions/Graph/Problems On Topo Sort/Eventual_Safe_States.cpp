#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> ingoing(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adj[graph[i][j]].push_back(i);
                ingoing[i]++;
            }
        }
        queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            if (!ingoing[i])
            {
                pq.push(i);
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            int node = pq.front();
            ans.push_back(node);
            pq.pop();

            for (auto &&nei : adj[node])
            {
                ingoing[nei]--;
                if (!ingoing[nei])
                {
                    pq.push(nei);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}