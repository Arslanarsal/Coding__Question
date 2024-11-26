#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define t tuple<int, int, int>
#define INF LLONG_MAX
#define pii pair<int, int>

vector<vector<pii>> adj, adj1;
int ans = INF, N;
vector<int> dist, dist1;

void bfs(int i, vector<vector<pii>> &adj, vector<int> &dist)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, i});
    dist[i] = 0;

    while (!q.empty())
    {
        pii it = q.top();
        q.pop();
        int dis = it.first;
        int node = it.second;

        if (dis > dist[node])
        {
            continue;
        }

        for (auto &&nei : adj[node])
        {
            int to = nei.first;
            int w = nei.second;
            if (dist[to] > w + dis)
            {
                dist[to] = w + dis;
                q.push({w + dis, to});
            }
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    N = n; 
    adj.resize(n + 1);
    adj1.resize(n + 1);
    dist.resize(n + 1, INF); 
    dist1.resize(n + 1, INF); 
    vector<t> e;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
        e.push_back({u, v, w});
    }

    bfs(1, adj, dist);
    bfs(n, adj1, dist1);
    int ans = INF;
    for (int i = 0; i < m; i++)
    {
        t it = e[i];
        int u = get<0>(it);
        int v = get<1>(it);
        int w = get<2>(it);
        if (dist[u] != INF && dist1[v] != INF)
        {
            ans = min(ans, dist[u] + dist1[v] + (w / 2));
        }
    }
    cout << ans << "\n";
    return 0;
}
