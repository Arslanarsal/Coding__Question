#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
int t, n, q, m, x;
const int N = 50005;
vector<int> adj[N];
bitset<N> bit[N];
vector<bitset<N>> NoOfNodes(N);
bool arr[N]{};
void dfs(int i)
{

    for (auto &&nei : adj[i])
    {
        if (!arr[i])
            dfs(nei);
        NoOfNodes[i] = (NoOfNodes[i] | NoOfNodes[nei]);
    }
    NoOfNodes[i].set(i);
    arr[i] = true;
}

int32_t main()
{
    fastio;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++)
    {
        if (!arr[i])
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
        cout << NoOfNodes[i].count() << " ";

    return 0;
}