#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vist(n + 1, 0);
    vector<int> way(n + 1);
    way[1] = 1;
    vist[0] = 1;
    vist[1] = 1;
    queue<int> q;
    q.push(1);
    bool flag = false;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            flag = true;
            break;
        }
        for (auto &&it : adj[node])
        {
            if (!vist[it])
            {
                vist[it] = 1;
                way[it] = node;
                q.push(it);
            }
        }
    }
    vector<int> ans;
    if (flag)
    {
        int i = n;
        while (way[i] != i)
        {
            ans.push_back(i);
            i = way[i];
        }
        ans.push_back(i);
    }
    else
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}