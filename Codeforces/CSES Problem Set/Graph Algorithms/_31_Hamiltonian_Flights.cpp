#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x;
vector<vector<int>> adj(20);
int dp[1 << 20][20];

int solve(int mask, int node)
{
    if (node == n - 1)
    {
        if (mask == ((1 << n) - 1))
            return 1;
        return 0;
    }

    int ans = 0;
    if (dp[mask][node] != -1)
    {
        return dp[mask][node];
    }
    for (auto &&nei : adj[node])
    {
        if (!(mask & (1 << nei)))
        {
            int mask1 = mask | (1 << nei);
            ans = (ans + solve(mask1, nei)) % mod;
        }
    }
    return dp[mask][node] = ans;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
        }
        memset(dp, -1, sizeof(dp));
        solve(1, 0);
        cout << dp[1][0] << "\n";
    }

    return 0;
}