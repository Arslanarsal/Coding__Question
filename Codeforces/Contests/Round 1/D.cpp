#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &vist, vector<int> &val)
{
    vist[i] = 1;
    int ans = val[i];
    int temp = INT_MAX;
    for (auto &&it : adj[i])
    {
        if (vist[it] == 0)
        {
            int ret = dfs(it, adj, vist, val);
            temp = min(temp, ret);
        }
    }
    if (i == 1)
    {
        return ans + temp;
    }

    if (temp <= ans )
    {
        return temp;
    }

    if (temp != INT_MAX)
    {
        ans = ans + (abs(temp - ans) / 2);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> val(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
        }
        vector<int> par(n + 1);
        for (int i = 2; i <= n; i++)
        {
            cin >> par[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 2; i <= n; i++)
        {
            adj[par[i]].push_back(i);
        }
        vector<int> vist(n + 1, 0);
        cout << dfs(1, adj, vist, val) << "\n";
    }
    return 0;
}
