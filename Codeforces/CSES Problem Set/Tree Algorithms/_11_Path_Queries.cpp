#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double

int t, n, q, m, x;
int val[200009]{};
vector<vector<int>> adj;
int inOut[200009][2]{};

struct BIT
{
    vector<int> bit;
    int N;
    BIT(int n)
    {
        N = n;
        bit.resize(n);
    }

    void insert(int idx, int val)
    {
        for (; idx < N; idx += (idx & (-idx)))
        {
            bit[idx] += val;
        }
    }

    int get_val(int idx)
    {
        int ans = 0;
        for (; idx > 0; idx -= (idx & (-idx)))
        {
            ans += bit[idx];
        }
        return ans;
    }
};

int timer = 1;

void dfs(int i, int p)
{
    inOut[i][0] = timer++;

    for (auto &&nei : adj[i])
    {
        if (nei != p)
        {
            dfs(nei, i);
        }
    }
    inOut[i][1] = timer - 1;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> q;
        adj.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, 0);
        BIT bit(n + 2);
        for (int i = 1; i <= n; i++)
        {
            bit.insert(inOut[i][0], val[i]);
            bit.insert(inOut[i][1] + 1, -val[i]);
        }

        while (q--)
        {
            int a, b, c;
            cin >> a;
            if (a == 1)
            {
                cin >> b >> c;
                bit.insert(inOut[b][0], c - val[b]);
                bit.insert(inOut[b][1] + 1, -(c - val[b]));
                val[b] = c;
            }
            else
            {
                cin >> b;
                int ans = bit.get_val(inOut[b][0]);
                cout << ans << "\n";
            }
        }
    }

    return 0;
}