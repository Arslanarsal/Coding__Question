#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;
vector<int> adj[50004], Radj[50004];
int comp[50004]{};
int cnt = 1;
vector<int> v;
vector<bool> vis(50004, 0);
vector<bitset<50004>> mask(50004);

void dfs(int i)
{
    vis[i] = true;
    for (auto &&nei : adj[i])
        if (!vis[nei])
            dfs(nei);

    v.push_back(i);
}

void dfs2(int node)
{
    vis[node] = true;
    comp[node] = cnt;
    for (auto &&nei : Radj[node])
        if (!vis[nei])
            dfs2(nei);
}

void dfs3(int node, vector<int> adj[])
{
    vis[node] = true;
    mask[node].set(node);
    for (auto &&it : adj[node])
    {
        if (!vis[it])
            dfs3(it, adj);

        mask[node] = mask[node] | mask[it];
    }
}

int32_t main()
{
    fastio;

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        Radj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    fill(vis.begin(), vis.end(), false);

    reverse(v.begin(), v.end());

    for (auto &&i : v)
    {
        if (!comp[i])
        {
            dfs2(i);
            cnt++;
        }
    }

    vector<int> newAdj[50004];
    for (int i = 1; i <= n; i++)
    {
        for (auto &&it : adj[i])
        {
            if (comp[i] != comp[it])
            {

                newAdj[comp[i]].push_back(comp[it]);
            }
        }
    }
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i < cnt; i++)
    {
        if (!vis[i])
        {
            dfs3(i, newAdj);
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (comp[a] == comp[b] || (mask[comp[a]].test(comp[b])))
        {
            cout << "YES\n";
        }
        else
        {

            cout << "NO\n";
        }
    }

    return 0;
}