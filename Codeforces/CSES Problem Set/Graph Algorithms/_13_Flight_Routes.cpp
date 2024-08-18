#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define int long long int
#define pii pair<int, int>

int n, m, k;
vector<vector<pii>> adj;
vector<vector<int>> dist;
vector<int> ans;

void bfs()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    // dist[1][0] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if (dist[u][k - 1] < d)
        {
            continue;
        }
        for (auto &&it : adj[u])
        {
            int node = it.first;
            int d1 = it.second;
            if (d + d1 < dist[node][k - 1])
            {
                dist[node][k - 1] = d + d1;
                q.push({d + d1, node});
                sort(dist[node].begin(), dist[node].end());
            }
        }
    }
}

int32_t main()
{
    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.resize(n + 1, vector<int>(k, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bfs();
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }

    return 0;
}