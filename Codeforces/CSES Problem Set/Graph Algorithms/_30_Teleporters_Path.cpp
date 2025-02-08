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

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        for (int i = 2; i < n; i++)
        {
            if ((indegree[i] - outdegree[i]) != 0)
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        if (!(abs(indegree[1] - outdegree[1]) & 1) || !(abs(indegree[n] - outdegree[n]) & 1))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        stack<int> st;
        st.push(1);
        vector<int> ans;
        while (!st.empty())
        {
            int node = st.top();

            int k = adj[node].size();

            if (k)
            {
                st.push(adj[node][k - 1]);
                adj[node].pop_back();
            }
            else
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        if (ans.size() != m + 1)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i = m; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}