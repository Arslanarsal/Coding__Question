#include <bits/stdc++.h>
using namespace std;

#define int long long

int distanc = 0;
int N;

int dfs(int pre, int i, vector<int> adj[], vector<int> &child, int d)
{
    distanc += d;
    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            child[i] += dfs(i, it, adj, child, d + 1);
        }
    }
    child[i] += 1;
    return child[i];
}

void dfs_dist(int pre, int i, vector<int> adj[], vector<int> &child, vector<int> &dist)
{
    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            dist[it] = dist[i] - child[it] + N - child[it];
            dfs_dist(i, it, adj, child, dist);
        }
    }
}

int32_t main()
{
    int n;
    cin >> n;
    N = n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> child(n + 1, 0);
    vector<int> dist(n + 1, 0);
    dfs(0, 1, adj, child, 0);
    dist[1] = distanc;
    dfs_dist(0, 1, adj, child, dist);
    for (int i = 1; i <= n; i++)
    {
        cout << (int)dist[i] << " ";
    }

    return 0;
}
