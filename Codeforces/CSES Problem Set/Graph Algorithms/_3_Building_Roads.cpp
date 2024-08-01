#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<int> &vist)
{
    vist[i] = 1;
    for (auto &&it : adj[i])
    {
        if (!vist[it])
        {
            dfs(it, adj, vist);
        }
    }
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
    vector<int> ans;
    vector<int> vist(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vist[i])
        {
            ans.push_back(i);
            dfs(i, adj, vist);
        }
    }
    int k = ans.size();
    cout << k - 1 << "\n";

    for (int i = 0; i < k - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }

    return 0;
}