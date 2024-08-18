#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n, m;
vector<vector<int>> adj;
vector<int> dp, visit;
int mod = 1e9 + 7;

void dfs(int u)
{
    visit[u] = 1;
    for (auto &&v : adj[u])
    {
        if (!visit[v])
        {
            dfs(v);
        }
        dp[u] = (dp[u] + dp[v]) % mod;
    }
}

int32_t main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    dp.resize(n + 1, 0);
    visit.resize(n + 1);
    dp[n] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(1);
    cout << dp[1];

    return 0;
}