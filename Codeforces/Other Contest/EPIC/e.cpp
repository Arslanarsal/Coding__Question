#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e3 + 10;
vector<int> child[N];
deque<ll> dep[N];
ll a[N];

ll dfs(int v)
{
    if (child[v].empty())
    {
        dep[v].push_back(1e15);
        return 0;
    }

    ll op = 0, sm = 0;
    for (int u : child[v])
    {
        op += dfs(u);
        sm += a[u];
        for (int i = 0; i < dep[u].size(); i++)
            if (i < dep[v].size())
                dep[v][i] += dep[u][i];
            else
                dep[v].push_back(dep[u][i]);
    }

    if (a[v] <= sm)
    {
        dep[v].push_front(sm - a[v]);
        return op;
    }

    dep[v].push_front(0);
    ll diff = a[v] - sm;
    for (int i = 0; i < dep[v].size(); i++)
    {
        ll mi = min(diff, dep[v][i]);
        diff -= mi;
        dep[v][i] -= mi;
        op += 1ll * i * mi;
    }

    return op;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        child[x].push_back(i);
    }

    cout << dfs(1) << endl;
    for (int i = 1; i <= n; i++)
        child[i].clear(), dep[i].clear();
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}