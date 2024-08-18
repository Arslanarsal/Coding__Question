#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define int long long int
#define pii pair<int, int>
#define t tuple<int, int, int>
int n, m;
vector<vector<pii>> adj;
int minprice = INF, timee = 0, mod = 1e9 + 7;
vector<int> dist, dp, maxfli, minfli;

void solve()
{
    priority_queue<t, vector<t>, greater<t>> q;
    dist[1] = 0;
    minfli[1] = 0;
    dp[1] = 1;
    q.push({0, 0, 1}); //  {price , number , Node}
    while (!q.empty())
    {
        t temp = q.top();
        q.pop();
        int price = get<0>(temp);
        int num = get<1>(temp);
        int node = get<2>(temp);

        if (dist[node] < price || minprice < price)
        {
            continue;
        }

        for (auto &&nei : adj[node])
        {
            int v = nei.first;
            int w = nei.second;
            if (minprice >= w + price)
            {
                if (dist[v] > w + price)
                {
                    dist[v] = w + price;
                    q.push({(w + price), (num + 1), v});
                    dp[v] = dp[node];
                    maxfli[v] = maxfli[node] + 1;
                    minfli[v] = minfli[node] + 1;
                }
                else if (dist[v] == w + price)
                {
                    maxfli[v] = max(maxfli[v], maxfli[node] + 1);
                    minfli[v] = min(minfli[v], minfli[node] + 1);
                    dp[v] = (dp[v] + dp[node]) % mod;
                }

                if (v == n && minprice >= w + price)
                {
                    minprice = w + price;
                }
            }
        }
    }
}

int32_t main()
{
    cin >> n >> m;

    adj.resize(n + 1);
    dp.resize(n + 1, 0);
    maxfli.resize(n + 1, 0);
    minfli.resize(n + 1, 1e16);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    solve();
    cout << minprice << " " << dp[n] << " " << minfli[n] << " " << maxfli[n] << " ";

    return 0;
}