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

pair<int, int> solve(int start, const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(start);
    dist[start] = 0;

    int ansnd = start, maxDist = 0;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        for (int nei : adj[node])
        {
            if (dist[nei] == -1)
            {
                dist[nei] = dist[node] + 1;
                que.push(nei);
                if (dist[nei] > maxDist)
                {
                    maxDist = dist[nei];
                    ansnd = nei;
                }
            }
        }
    }
    return make_pair(ansnd, maxDist);
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        int vvv;
        cin >> vvv;

        vector<vector<int>> adj(vvv);

        for (int i = 0; i < vvv - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        pair<int, int> ans = solve(0, adj);
        int nodee = ans.first;
        int _ = ans.second;

        ans = solve(nodee, adj);
        int dd = ans.second;

        vector<int> deg(vvv, 0);
        for (int i = 0; i < vvv; i++)
        {
            deg[i] = adj[i].size();
        }

        vector<pair<int, int>> degnd;
        for (int i = 0; i < vvv; i++)
        {
            degnd.emplace_back(deg[i], i);
        }
        sort(degnd.rbegin(), degnd.rend());

        int temp1 = degnd[0].second;
        int temp2 = degnd[1].second;

        cout << dd << " " << deg[temp1] << " " << deg[temp2] << "\n";
    }

    return 0;
}