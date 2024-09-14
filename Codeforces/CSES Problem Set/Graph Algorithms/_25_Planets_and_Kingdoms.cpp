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

void dfs(int i, vector<int> &visit)
{
    visit[i] = true;
    for (auto &child : adj[i])
    {
        if (!visit[child])
        {
            dfs(child, visit);
        }
    }
    st.push(i);
}

void dfs2(int i, vector<int> &visit, int &j)
{
    visit[i] = j;
    for (auto &child : radj[i])
    {
        if (!visit[child])
        {
            dfs2(child, visit, j);
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
        vector<int> visit(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                dfs(i, visit);
            }
        }

        visit.assign(n + 1, 0);
        int j = 1;
        while (!st.empty())
        {
            int i = st.top();
            st.pop();
            if (!visit[i])
            {
                dfs2(i, visit, j);
                j++;
            }
        }

        cout << j - 1 << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << visit[i] << " ";
        }
    }

    return 0;
}