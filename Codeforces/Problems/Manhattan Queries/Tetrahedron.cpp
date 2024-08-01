#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int solve(bool flag, int n, vector<vector<int>> &dp)
{
    if (dp[flag][n] != -1)
    {
        return dp[flag][n];
    }

    if (flag)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return dp[flag][n] = ((3 * 1LL * solve(!flag, n - 1, dp)) % mod);
        }
    }

    if (n == 0)
    {
        return 0;
    }
    else
    {
        return dp[flag][n] = ((2 * 1LL * solve(flag, n - 1, dp)) + 0LL + solve(!flag, n - 1, dp)) % mod;
    }
}

int main()
{
    int n;
    cin >> n;
    // vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    // cout << solve(true, n, dp);
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    dp[1][0] = 1;

    for (int j = 1; j <= n; j++)
    {

        dp[1][j] = ((3 * 1LL * dp[0][j - 1])) % mod;

        dp[0][j] = ((2 * 1LL * dp[0][j - 1]) + 0LL + dp[1][j - 1]) % mod;
    }

    cout << dp[1][n];

    return 0;
}