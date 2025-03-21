#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define R0F(i, a) for (int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for (int i = (b); i >= a; i--)
#define trav(a, x) for (auto &a : x)

int n, m;
ll adj[501][501], oadj[501][501];

ll flow[501];
bool V[501];
int pa[501];
using pii = pair<int, int>;
vector<pii> ans;

bool reachable()
{
    memset(V, false, sizeof(V));
    queue<int> Q;
    Q.push(1);
    V[1] = 1;
    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        FOR(j, 1, n)
        if (adj[i][j] && !V[j])
            V[j] = 1, pa[j] = i, Q.push(j);
    }
    return V[n];
}

int main()
{
    cin >> n >> m;
    FOR(i, 1, n)
    FOR(j, 1, n)
    adj[i][j] = oadj[i][j] = 0;
    F0R(i, m)
    {
        ll a, b;
        cin >> a >> b;
        adj[a][b]++, adj[b][a]++;
        oadj[a][b]++, oadj[b][a]++;
    }
    int v, u;
    while (reachable())
    {
        ll flow = 1e18;
        for (v = n; v != 1; v = pa[v])
        {
            u = pa[v];
            flow = min(flow, adj[u][v]);
        }
        for (v = n; v != 1; v = pa[v])
        {
            u = pa[v];
            adj[u][v] -= flow;
            adj[v][u] += flow;
        }
    }
    reachable();
    FOR(i, 1, n)
    FOR(j, 1, n)
    if (V[i] && !V[j] && oadj[i][j])
        ans.pb({i, j});
    cout << ans.size() << '\n';
    trav(a, ans) cout << a.f << " " << a.s << '\n';
}