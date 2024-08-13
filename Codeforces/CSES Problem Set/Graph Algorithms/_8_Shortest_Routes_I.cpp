#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define int long long int

#define pii pair<long long, long long>

vector<int> ans;
vector<vector<pii>> adj;

void solve()
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push({0, 0});
    ans[0] = 0;
    while (!p.empty())
    {
        int node = p.top().second;
        int dist = p.top().first;
        p.pop();

        if (dist > ans[node])
            continue;

        for (auto &&nei : adj[node])
        {
            int n = nei.first;
            int w = nei.second;
            if (ans[n] > w + dist)
            {
                ans[n] = w + dist;
                p.push({ans[n], n});
            }
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    ans.resize(n, INF);
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        adj[u].push_back({v, l});
    }
    solve();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
