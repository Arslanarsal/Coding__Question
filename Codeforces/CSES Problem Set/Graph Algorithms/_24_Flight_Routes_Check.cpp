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
int t, n, q, m;
vector<vector<int>> adj, radj;
stack<int> st;

void dfs(int n, vector<bool> &visit)
{
    visit[n] = true;
    for (auto &&it : adj[n])
    {
        if (!visit[it])
        {
            dfs(it, visit);
        }
    }
    st.push(n);
}

void dfs2(int n, vector<bool> &visit)
{
    visit[n] = true;
    for (auto &&it : radj[n])
    {
        if (!visit[it])
        {
            dfs2(it, visit);
        }
    }
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        adj.resize(n + 1);
        radj.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            radj[b].push_back(a);
        }
        vector<bool> visit(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                dfs(i, visit);
            }
        }
        vector<int> scc;
        visit.assign(n + 1, false);

        while (!st.empty())
        {
            int i = st.top();
            st.pop();
            if (!visit[i])
            {
                scc.push_back(i);
                dfs2(i, visit);
            }
        }
        if (scc.size() > 1)
        {
            cout << "NO\n";
            cout << scc[1] << " " << scc[0] << "\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}