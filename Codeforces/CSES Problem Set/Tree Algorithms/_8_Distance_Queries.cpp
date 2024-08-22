#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
vector<vector<int>> lifting(2e5 + 2, vector<int>(30, -1));
vector<vector<int>> adj(2e5 + 2);
vector<int> level(2e5 + 2, 0);

void dfs(int u, int h)
{
    level[u] = h;
    for (auto &&it : adj[u])
    {
        dfs(it, h + 1);
    }
}

int solve(int a, int k)
{
    for (int i = 0; i < 30; i++)
    {
        if ((1 << i) & k)
        {
            a = lifting[a][i];
        }
    }
    return a;
}

int solve_2(int a, int b)
{
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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        lifting[b][0] = a;
    }
    dfs(1, 0);

    for (int i = 1; i < 30; i++)
    {
        for (int j = 2; j <= n; j++)
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
        int oa = a, ob = b;
        if (level[a] > level[b])
        {
            swap(a, b);
        }
        int d = level[b] - level[a];
        b = solve(b, d);

        int lca = solve_2(a, b);
        cout << level[oa] + level[ob] - 2 * level[lca] << "\n";
    }

    return 0;
}