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

vector<vector<int>> adj;
vector<vector<int>> radj;
stack<int> st;

void dfs(int n, vector<int> &color)
{
    color[n] = 1;
    for (auto &it : adj[n])
    {
        if (!color[it])
        {
            dfs(it, color);
        }
    }
    st.push(n);
}

void dfs2(int n, vector<int> &color, int &y)
{
    color[n] = y;
    for (auto &it : radj[n])
    {
        if (!color[it])
        {
            dfs2(it, color, y);
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
        adj.resize(m * 2);
        radj.resize(m * 2);
        char c1, c2;
        int u, v;

        for (int i = 0; i < n; i++)
        {
            cin >> c1 >> u >> c2 >> v;
            int d1 = c1 == '+' ? 1 : 0;
            int d2 = c2 == '+' ? 1 : 0;
            u--;
            v--;
            adj[m * (1 - d1) + u].push_back(m * d2 + v);
            radj[m * d2 + v].push_back(m * (1 - d1) + u);
            adj[m * (1 - d2) + v].push_back(m * d1 + u);
            radj[m * d1 + u].push_back(m * (1 - d2) + v);
        }
        vector<int> color(2 * m , 0);
        for (int i = 0; i < 2 * m; i++)
        {
            if (!color[i])
            {
                dfs(i, color);
            }
        }
        color.assign(2 * m , 0);
        int y = 1;
        while (!st.empty())
        {
            int i = st.top();
            st.pop();
            if (!color[i])
            {
                dfs2(i, color, y);
                y++;
            }
        }
        vector<char> ans(m);
        for (int i = 0; i < m; i++)
        {
            if (color[i] == color[i + m])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }

            if (color[i] < color[i + m])
            {
                ans[i] = '+';
            }
            else
            {
                ans[i] = '-';
            }
        }

        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}