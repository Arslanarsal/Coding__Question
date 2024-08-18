#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pii pair<int, int>
#define pp pop_back
#define INF LLONG_MAX
int n, m;
vector<vector<int>> adj;
vector<int> visit, dist, par;

void dfs(int node)
{
    visit[node] = 1;
    for (auto &&v : adj[node])
    {
        if (visit[v] == 0)
        {
            dfs(v);
        }
        if (dist[v] != -1 && dist[node] < dist[v] + 1)
        {
            dist[node] = dist[v] + 1;
            par[node] = v;
        }
    }
}

int32_t main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1, -1);
    visit.resize(n + 1, 0);
    dist[n] = 1;
    par.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    dfs(1);
    if (dist[1] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    int temp = 1;
    while (temp != -1)
    {
        ans.push_back(temp);
        temp = par[temp];
    }
    int k = ans.size();
    cout<<k<<"\n";
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}