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
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m;
vector<vector<pair<int, int>>> adj;

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        adj.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<bool> visit(n + 1, false);

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (visit[node])
            {
                continue;
            }
            sum += dist;
            visit[node] = true;
            for (auto &&nei : adj[node])
            {
                int d = nei.second;
                int neii = nei.first;
                if (!visit[neii])
                {
                    pq.push({d, neii});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }

        cout << sum << "\n";
    }

    return 0;
}