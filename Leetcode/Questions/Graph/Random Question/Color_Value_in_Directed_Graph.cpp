#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (auto &&it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> t(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            ans = max(ans, t[node][colors[node] - 'a']);

            for (auto &&it : adj[node])
            {
                for (int i = 0; i < 26; i++)
                {
                    t[it][i] = max(t[it][i], t[node][i] + (colors[it] - 'a' == i));
                }
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (count < n)
        {
            return -1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}