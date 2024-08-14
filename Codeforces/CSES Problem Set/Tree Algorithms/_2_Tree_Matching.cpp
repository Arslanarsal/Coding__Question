#include <bits/stdc++.h>
using namespace std;

int N;
vector<bool> visit;
int ans = 0;

void dfs(int pre, int i, vector<vector<int>> &adj)
{
    for (auto &&it : adj[i])
    {
        if (it != pre)
        {
            dfs(i, it, adj);
            if (!visit[it] && !visit[i])
            {
                visit[i] = true;
                visit[it] = true;
                ans++;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    N = n;
    visit.resize(N + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1, adj);

    cout << ans;

    return 0;
}
