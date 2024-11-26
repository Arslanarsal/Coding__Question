#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX   
#define int long long int
vector<vector<int>> adj, a, b;
vector<int> dist, vist, vist1;
int flag = 0;

void bellmanford(int n)
{
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (auto &&it : adj)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != INF && vist1[v] && vist[u] && dist[u] + w < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + w;
            }
        }
    }
}

void dfs(int u, vector<int> &v, vector<vector<int>> &g)
{
    v[u] = 1;
    for (auto &&e : g[u])
    {
        if (!v[e])
        {
            dfs(e, v, g);
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(m);
    a.resize(n + 1);
    b.resize(n + 1);
    vist.resize(n + 1, 0);
    vist1.resize(n + 1, 0);
    dist.resize(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        a[u].push_back(v);
        b[v].push_back(u);
        adj[i] = {u, v, -wt};
    }
    dfs(1, vist, a);
    dfs(n, vist1, b);
    bellmanford(n);
    if (flag)
    {
        cout << -1 << "\n";
    }
    else
    {

        cout << dist[n] * -1 << "\n";
    }
    return 0;
}
