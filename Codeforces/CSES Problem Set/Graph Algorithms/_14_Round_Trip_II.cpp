#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LLONG_MAX
#define pii pair<int, int>

int n, m;
vector<vector<int>> adj;
vector<int> ans;
stack<int> st;
vector<bool> vist, resvisit;

bool dfs(int i)
{
    vist[i] = true;
    resvisit[i] = true;
    st.push(i);
    for (auto &&v : adj[i])
    {
        if (!vist[v])
        {
            if (dfs(v))
            {
                return true;
            }
        }
        else if (resvisit[v])
        {
            // Cycle detected
            st.push(v);
            return true;
        }
    }
    st.pop();
    resvisit[i] = false;
    return false;
}

int32_t main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vist.resize(n + 1, false);
    resvisit.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vist[i])
        {
            if (dfs(i))
            {
                break;
            }
        }
    }

    if (st.empty())
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int cycle_start = st.top();
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
        if (!st.empty() && st.top() == cycle_start)
        {
            ans.push_back(st.top());
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    int k = ans.size();
    cout << k << "\n";
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
