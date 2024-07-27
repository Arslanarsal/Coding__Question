#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        int n = original.size();
        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
                    {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                if (adj[u][v] == INT_MAX)
                {
                    return -1;
                }
                ans += adj[u][v];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}