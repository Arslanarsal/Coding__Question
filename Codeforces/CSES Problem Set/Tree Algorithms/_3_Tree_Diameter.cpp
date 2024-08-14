#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN;

int dfs(int pre, int i, vector<int> adj[])
{
    int left = 0, right = 0;
    int n = adj[i].size();
    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            int ret = dfs(i, it, adj);
            if (ret > left)
            {
                right = left;
                left = ret;
            }
            else if (ret > right)
            {
                right = ret;
            }
        }
    }
    ans = max(ans, left + right);
    return left + 1;
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
    dfs(0, 1, adj);
    cout << ans << "\n";

    return 0;
}