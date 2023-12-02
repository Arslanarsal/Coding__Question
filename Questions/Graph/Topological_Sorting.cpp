#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity O(N)
    Space Complexity: O(N)

    where N is the number of nodes in the graph i.e N = 'nodes'.
*/

void dfs(int idx, vector<vector<int>> &g, vector<int> &ans, vector<int> &vis)
{
    if (vis[idx])
        return;
    vis[idx] = 1;
    for (int next : g[idx])
        dfs(next, g, ans, vis);

    ans.push_back(idx);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{

    vector<vector<int>> g(nodes + 1);
    for (vector<int> edge : graph)
        g[edge[0]].push_back(edge[1]);

    vector<int> ans;
    vector<int> vis(nodes + 1, 0);
    for (int i = 0; i < nodes; i++)
    {
        if (!vis[i])
        {
            dfs(i, g, ans, vis);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}
