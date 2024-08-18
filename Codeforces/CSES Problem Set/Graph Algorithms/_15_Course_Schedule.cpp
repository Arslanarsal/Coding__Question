#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define INF LLONG_MAX

int n, m;
vector<vector<int>> adj;
vector<int> in;
stack<int> st;

int32_t main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    in.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
        in[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        st.push(u);
        for (auto v : adj[u])
        {
            in[v]--;
            if (!in[v])
            {
                q.push(v);
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.pb(st.top());
        st.pop();
    }
    int k = ans.size();
    if (k != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
