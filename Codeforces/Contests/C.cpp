

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
int t, n, q, m, x, k;

struct Edge
{
    int to;
    double weight;
};

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        double d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    double ans = 1;
    double temp = LLONG_MAX;

    for (int start = 1; start <= N; ++start)
    {
        vector<double> dist(N + 1, LLONG_MAX);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int nod = it.second;
            pq.pop();

            if (dis > dist[nod])
                continue;

            for (const auto &edge : graph[nod])
            {
                double newDist = dis + edge.weight;
                if (newDist < dist[edge.to])
                {
                    dist[edge.to] = newDist;
                    pq.push({newDist, edge.to});
                }
            }
        }

        double totalDelay = 0;
        for (int i = 1; i <= N; ++i)
        {
            totalDelay += dist[i];
        }

        double averageDelay = totalDelay / N;

        if (averageDelay < temp)
        {
            temp = averageDelay;
            ans = start;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio;

    cin >> t;

    while (t--)
    {

        solve();
    }

    return 0;
}