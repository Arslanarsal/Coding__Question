#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int n, q;
vector<vector<int>> lifting(2e5 + 2, vector<int>(30, -1));
vector<vector<int>> adj(2e5 + 2);
vector<int> level(2e5 + 2), pre(2e5 + 2);

void dfs(int u, int p, int h)
{
    level[u] = h;
    lifting[u][0] = p;
    for (auto &&it : adj[u])
    {
        if (it != p)
        {
            dfs(it, u, h + 1);
        }
    }
}

int dfs_2(int u, int p)
{
    int ans = pre[u];
    lifting[u][0] = p;
    for (auto &&it : adj[u])
    {
        if (it != p)
        {
            ans += dfs_2(it, u);
        }
    }
    pre[u] = ans;
    return ans;
}

int solve(int a, int k)
{
    for (int i = 0; i < 30; i++)
    {
        if (1 << i & k)
        {
            a = lifting[a][i];
        }
    }
    return a;
}

int lca(int a, int b)
{
    if (level[a] > level[b])
    {
        swap(a, b);
    }
    int diff = level[b] - level[a];
    b = solve(b, diff);

    if (a == b)
        return a;

    for (int i = 29; i >= 0; i--)
    {
        if (lifting[a][i] != lifting[b][i])
        {
            a = lifting[a][i];
            b = lifting[b][i];
        }
    }
    return lifting[b][0];
}

int32_t main()
{
    fastio;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, 0);
    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp = lifting[j][i - 1];
            if (temp != -1)
            {
                lifting[j][i] = lifting[temp][i - 1];
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        pre[a]++;
        pre[b]++;
        int lc = lca(a, b);
        pre[lc]--;

        if (lifting[lc][0] != -1)
        {
            pre[lifting[lc][0]]--;
        }
    }
    dfs_2(1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << pre[i] << " ";
    }

    return 0;
}