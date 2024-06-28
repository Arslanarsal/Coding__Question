#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<int> &dfsnum, vector<int> &low, vector<int> &parent, vector<int> &node, vector<int> &visit, long long &ans, int &n)
{
    static int time = 0;
    visit[i] = 1;
    dfsnum[i] = low[i] = ++time;
    node[i] = 1;

    for (auto &&it : adj[i])
    {
        if (!visit[it])
        {
            parent[it] = i;
            dfs(it, adj, dfsnum, low, parent, node, visit, ans, n);

            // Check if the subtree rooted at it has a connection back to an ancestor of i
            low[i] = min(low[i], low[it]);

            // If it is not part of the same subtree, we found a bridge
            if (low[it] > dfsnum[i])
            {
                long long node1 = node[it];
                long long node2 = n - node1;
                long long temp = ((node1 * (node1 - 1)) / 2) + ((node2 * (node2 - 1)) / 2);
                ans = min(ans, temp);
            }

            node[i] += node[it];
        }
        else if (it != parent[i])
        {
            // Update low value of i for parent function calls.
            low[i] = min(low[i], dfsnum[it]);
        }
    }
}

int main()
{
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> node(n + 1, 0), dfsnum(n + 1, 0), low(n + 1, 0), parent(n + 1, -1), visit(n + 1, 0);
        long long ans = LLONG_MAX;

        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                dfs(i, adj, dfsnum, low, parent, node, visit, ans, n);
            }
        }
        if (ans == LLONG_MAX)
        {
            ans = (n * (n - 1)) / 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
