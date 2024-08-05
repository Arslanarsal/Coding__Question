#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, bool turn, vector<vector<int>> &adj, vector<int> &group)
{
    if (group[i] == -1)
    {
        group[i] = turn;
    }
    else
    {
        if (group[i] == turn)
        {
            return true;
        }
        return false;
    }

    for (auto &&it : adj[i])
    {
        if (it != i && !(dfs(it, !turn, adj, group)))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> group(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (group[i] == -1 && !dfs(i, 0, adj, group))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (group[i])
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }
    }

    return 0;
}