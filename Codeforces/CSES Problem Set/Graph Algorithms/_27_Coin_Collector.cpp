#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller than X]
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
const int node = 1e5 + 2;

int t, n, m;
vector<int> coin, dp, pre(node, -1), low(node, 0), scc(node, 0), visit(node, 0);
set<int> meta[node];
vector<vector<int>> adj;
stack<int> toposort;
int sccid = 1, cnt = 0;

void dfs(int u, stack<int> &st)
{
    st.push(u);
    pre[u] = low[u] = cnt++;

    for (auto &v : adj[u])
    {
        if (pre[v] == -1)
        {
            dfs(v, st);
        }
        low[u] = min(low[u], low[v]);
    }

    // If u is the root of an SCC
    if (low[u] == pre[u])
    {
        while (true)
        {
            int v = st.top();
            st.pop();
            // low[v] = node;
            scc[v] = sccid;
            if (v == u)
                break;
        }
        sccid++;
    }
}

void dfs2(int u)
{
    visit[u] = 1;
    for (auto v : meta[u])
    {
        if (!visit[v])
        {
            dfs2(v);
        }
    }
    toposort.push(u);
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        coin.resize(n + 1);
        dp.resize(node, 0);
        adj.resize(n + 1);
        fill(visit.begin(), visit.end(), 0); // Reset visit vector
        fill(pre.begin(), pre.end(), -1);    // Reset pre vector
        fill(low.begin(), low.end(), 0);     // Reset low vector
        fill(scc.begin(), scc.end(), 0);     // Reset scc vector
        sccid = 1;                           // Reset SCC ID
        cnt = 0;                             // Reset counter

        for (int i = 1; i <= n; i++)
        {
            cin >> coin[i];
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        stack<int> st;
        // For strong component
        for (int i = 1; i <= n; i++)
        {
            if (pre[i] == -1)
            {
                dfs(i, st);
            }
        }
        
        vector<int> val(node, 0);
        for (int i = 1; i <= n; i++)
        {
            for (auto &&j : adj[i])
            {
                if (scc[i] != scc[j])
                {
                    meta[scc[i]].insert(scc[j]);
                }
            }
            val[scc[i]] += coin[i];
        }

        for (int i = 1; i < sccid; i++)
        {
            if (!visit[i])
            {
                dfs2(i);
            }
            dp[i] = val[i];
        }

        while (!toposort.empty())
        {
            int u = toposort.top();
            toposort.pop();
            for (auto &j : meta[u])
            {
                dp[j] = max(dp[j], dp[u] + val[j]);
            }
        }

        int ans = 0;
        for (int i = 1; i < sccid; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans;
    }

    return 0;
}
