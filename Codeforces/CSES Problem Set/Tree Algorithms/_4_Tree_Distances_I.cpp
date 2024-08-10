#include <bits/stdc++.h>
using namespace std;

void dfs(int pre, int i, vector<int> adj[], vector<int> &in)
{
    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            dfs(i, it, adj, in);
            in[i] = max(in[i], 1 + in[it]);
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
            if (in[it] >= maxele)
            {
                secmaxele = maxele;
                maxele = in[it];
            }
            else if (in[it] > secmaxele)
            {
                secmaxele = in[it];
            }
        }
    }

    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            int l = maxele;
            if (in[it] == l)
            {
                l = secmaxele;
            }
            out[it] = 1 + max(out[i], 1 + l);
            dfs(i, it, adj, in, out);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in(n + 1, 0);
    dfs(0, 1, adj, in);

    vector<int> out(n + 1, 0);
    dfs(0, 1, adj, in, out);

    for (int i = 1; i <= n; i++)
    {
        cout << max(in[i], out[i]) << " ";
    }

    return 0;
}
