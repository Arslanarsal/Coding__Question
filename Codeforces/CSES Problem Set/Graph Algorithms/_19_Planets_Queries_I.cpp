#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
const int mod = 1e9 + 7;
int n, q;
const int N = 2e5 + 2;
// vector<vector<int>> lifting(N, vector<int>(30)); // Adjusted size
int lifting[N][30];

int solve(int x, int k)
{
    for (int i = 0; i < 30; i++)
    {
        if ((1LL << i) & k)
        {
            x = lifting[x][i];
        }
    }
    return x;
}

int32_t main()
{
    fastio;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> lifting[i][0];
    }
    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lifting[j][i] = lifting[lifting[j][i - 1]][i - 1];
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        cout << solve(x, k) << "\n";
    }

    return 0;
}
