#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;

int n, q;
vector<vector<int>> lifting(2e5 + 2, vector<int>(30, -1));
vector<vector<int>> adj(2e5 + 2);
vector<int> level(2e5 + 2, 0);

void dfs(int i, int h)
{
    level[i] = h;
    for (auto &&it : adj[i])
    {
        dfs(it, h + 1);
    }
}

int solve(int x, int k)
{
    for (int i = 29; i >= 0; i--)
    {
        if ((1 << i) & k)
        {
            x = lifting[x][i];
        }
        if (x == -1)
        {
            return x;
        }
    }
    return x;
}

int solve_2(int a, int b)
{
    if (a == b)
        return a;
    // cout << a << " " << b << " \n";

    for (int i = 29; i >= 0; i--)
    {
        // cout << lifting[a][i] << " " << lifting[b][i] << "\n";
        if (lifting[a][i] != lifting[b][i])
        {
            a = lifting[a][i];
            b = lifting[b][i];
        }
    }
    return lifting[a][0]; // One step high
}

int32_t main()
{
    fastio;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int node;
        cin >> node;
        adj[node].push_back(i);
        lifting[i][0] = node;
    }

    dfs(1, 0);

    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp = lifting[j][i - 1];
            if (temp != -1)
            {
                lifting[j][i] = lifting[temp][i - 1];
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {

    //     cout << lifting[i][3] << " ";

    //     cout << endl;
    // }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (level[a] > level[b])
        {
            swap(a, b);
        }
        int d = level[b] - level[a];
        b = solve(b, d);

        cout << solve_2(a, b) << "\n";
    }

    return 0;
}
