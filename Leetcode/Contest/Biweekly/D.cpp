#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int pre, int i, vector<int> adj[], vector<int> &in)
    {
        for (auto &&it : adj[i])
        {
            if (it != pre)
            {
                dfs(i, it, adj, in);
                if (it & 1)
                {
                    in[i] = max(in[i], in[it] + 1);
                }
                else
                {
                    in[i] = max(in[i], in[it] + 2);
                }
            }
        }
    }

    void dfs(int pre, int i, vector<int> adj[], vector<int> &in, vector<int> &out)
    {
        int maxele = -1, secmaxele = -1;

        for (auto &&it : adj[i])
        {
            if (it != pre)
            {
                int op = (it & 1) ? 1 : 2;
                if (in[it] + op >= maxele)
                {
                    secmaxele = maxele;
                    maxele = in[it] + op;
                }
                else if (in[it] + op > secmaxele)
                {
                    secmaxele = in[it] + op;
                }
            }
        }

        for (auto &&it : adj[i])
        {
            if (it != pre)
            {
                int l = maxele;
                int op = (it & 1) ? 1 : 2;

                if (in[it] + op == l)
                {
                    l = secmaxele;
                }
                int op1 = (i & 1) ? 1 : 2;

                out[it] = op1 + max(out[i], l);

                dfs(i, it, adj, in, out);
            }
        }
    }

public:
    vector<int> timeTaken(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> in(n + 1, 0), out(n + 1, 0);
        dfs(-1, 0, adj, in);
        for (int i = 0; i <= n; i++)
        {
            cout << in[i] << " ";
        }
        cout << endl;
        dfs(-1, 0, adj, in, out);
        for (int i = 0; i <= n; i++)
        {
            cout << out[i] << " ";
        }
        for (int i = 0; i <= n; i++)
        {
            in[i] = max(in[i], out[i]);
        }
        return in;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{0, 1}, {0, 2}};
    sol.timeTaken(v);
    return 0;
}
