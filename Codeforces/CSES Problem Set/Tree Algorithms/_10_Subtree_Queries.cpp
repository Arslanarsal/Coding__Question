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
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q;

const int maxval = 2e5 + 4;

int tin[maxval]{}, tout[maxval]{};
int BIT[maxval * 2]{};
vector<vector<int>> adj(maxval);
int tim = 0;

void update(int ind, int val)
{
    ind;
    for (; ind < maxval * 2; ind += (ind & (-ind)))
    {
        BIT[ind] += val;
    }
}

int getVal(int ind)
{
    ind;
    int ans = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
    {
        ans += BIT[ind];
    }
    return ans;
}

void dfs(int u, int par = 0)
{
    tin[u] = ++tim;
    for (auto &&nei : adj[u])
    {
        if (nei != par)
        {
            dfs(nei, u);
        }
    }
    tout[u] = ++tim;
}

int32_t main()
{
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        
        for (int i = 1; i <= n; i++)
            update(tout[i], arr[i]);

        while (q--)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                int s, k;
                cin >> s >> k;
                update(tout[s], -arr[s]);
                arr[s] = k;
                update(tout[s], k);
            }
            else
            {
                int ind;
                cin >> ind;
                cout << getVal(tout[ind]) - getVal(tin[ind]) << "\n";
            }
        }
    }

    return 0;
}
