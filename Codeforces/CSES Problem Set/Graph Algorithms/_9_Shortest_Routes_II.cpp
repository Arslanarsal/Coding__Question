#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LLONG_MAX
#define pii pair<int, int>
vector<vector<int>> dist;
int n, m, q;

void solve()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return;
}

int32_t main()
{

    cin >> n >> m >> q;

    dist.resize(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        dist[u][v] = min(dist[u][v], l);
        dist[v][u] = min(dist[v][u], l);
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    solve();
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] == INF)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[a][b] << "\n";
        }
    }

    return 0;
}