#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;

vector<vector<int>> adj(501), CSpeed(501, vector<int>(501, 0));

int maxiDownSpeed()
{
    int ans = 0;
    vector<int> parent(n, -1);
    auto reachAble = [&]() -> bool
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &&nei : adj[node])
            {
                if (CSpeed[node][nei] && parent[nei] == -1)
                {
                    q.push(nei);
                    parent[nei] = node;
                }
            }
        }
        return parent[n - 1] != -1;
    };

    while (reachAble())
    {
        int min_temp = LLONG_MAX;
        int node = n - 1;
        while (node)
        {
            min_temp = min(min_temp, CSpeed[parent[node]][node]);
            node = parent[node];
        }
        ans += min_temp;
        node = n - 1;
        while (node)
        {
            CSpeed[parent[node]][node] -= min_temp;
            CSpeed[node][parent[node]] += min_temp;

            node = parent[node];
        }
        fill(parent.begin(), parent.end(), -1);
    }
    return ans;
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
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            CSpeed[a][b] += c;
        }
        cout << maxiDownSpeed();
    }

    return 0;
}