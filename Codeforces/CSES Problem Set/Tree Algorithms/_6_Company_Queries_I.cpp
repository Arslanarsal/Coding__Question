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

int solve(int x, int k)
{
    for (int i = 0; i < 30; i++)
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

int32_t main()
{
    fastio;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> lifting[i][0];
    }

    for (int i = 1; i < 30; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int temp = lifting[j][i - 1];
            if (temp != -1)
            {
                lifting[j][i] = lifting[temp][i - 1];
            }
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