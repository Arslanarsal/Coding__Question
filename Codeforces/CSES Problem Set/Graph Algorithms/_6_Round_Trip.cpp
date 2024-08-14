#include <bits/stdc++.h>
using namespace std;

bool flag = false, flag1 = false;
vector<bool> vist;
vector<int> ans;
int startnode = -2;

void dfs(int pre, int i, vector<int> adj[])
{
    vist[i] = true;
    for (auto &&it : adj[i])
    {
        if (it != pre && !vist[it])
        {
            dfs(i, it, adj);
            if (flag)
            {
                ans.push_back(i);
                if (i == startnode)
                {
                    flag = false;
                }
                return;
            }
            if (flag1)
            {
                return;
            }
        }
        else if (it != pre && vist[it])
        {
            ans.push_back(it);
            ans.push_back(i);
            startnode = it;
            flag1 = true;
            flag = true;
            return;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vist.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 1; i < n; i++)
    {
        if (!vist[i])
        {
            dfs(-1, i, adj);
            if (flag1)
            {
                break;
            }
        }
    }

    int t = ans.size();
    if (t == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << t << "\n";

    for (auto &&it : ans)
    {
        cout << it << " ";
    }

    return 0;
}