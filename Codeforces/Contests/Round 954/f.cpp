#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 4;
int n, m, df[N], lo[N], sz[N];
vector<int> g[N];
bool v[N];
ll ans;
int cnt;
void dfs(int x, int f)
{
    df[x] = lo[x] = ++cnt, sz[x] = 1, v[x] = 1;
    for (auto y : g[x])
        if (y != f)
        {
            if (!v[y])
                dfs(y, x), sz[x] += sz[y];
            lo[x] = min(lo[x], lo[y]);
        }
    if (df[x] == lo[x])
    {
        cout << (ll)sz[x] * (n - sz[x]) << " " << x << " " << sz[x] << " \n";
        ans = max(ans, (ll)sz[x] * (n - sz[x]));
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            g[i].clear(), v[i] = 0;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }

        ans = 0, dfs(1, 0);

        cout << (ll)n * (n - 1) / 2 - ans << '\n';
    }
}