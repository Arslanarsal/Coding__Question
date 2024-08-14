#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &ans)
{
    int num = 0;
    for (auto &&it : adj[i])
    {
        num += dfs(it, adj, ans);
    }
    ans[i] = num;
    return num + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> input[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        adj[input[i]].push_back(i);
    }

    vector<int> ans(n + 1, 0);
    dfs(1, adj, ans);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}