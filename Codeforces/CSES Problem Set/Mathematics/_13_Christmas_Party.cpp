#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
int n;

int solve(int i)
{
    if (i <= 1)
    {
        return i ? 0 : 1;
    }

    return ((i - 1) * ((solve(i - 2) + solve(i - 1) % mod))) % mod;
}

int32_t main()
{
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = ((i - 1) * ((dp[(i - 2)] + dp[(i - 1)] % mod))) % mod;
    }

    // cout << solve(n);
    cout << dp[(n)];

    return 0;
}