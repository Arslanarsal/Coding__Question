#include <bits/stdc++.h>
using namespace std;

int N;

// Recursive function with memoization to solve the problem
int solve(int i, int j, vector<string> &grid, vector<vector<int>> &dp)
{
    if (i >= N || j >= N || i < 0 || j < 0)
    {
        return 0;
    }
    if (i == N - 1 && j == N - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (j + 1 < N && grid[i][j + 1] == '.')
    {
        ans += solve(i, j + 1, grid, dp);
    }
    if (i + 1 < N && grid[i + 1][j] == '.')
    {
        ans += solve(i + 1, j, grid, dp);
    }
    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;
    // N = n;
    vector<string> st(n);
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }
    if (st[0][0] != '.' || st[n - 1][n - 1] != '.')
    {
        cout << 0 << "\n";
        return 0;
    }
    int mod = 1e9 + 7;

    // Commented out the recursive solution with memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << solve(0, 0, st, dp) << "\n";

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        if (st[n - 1][i] == '.')
        {
            dp[n - 1][i] = 1;
        }
        else
        {
            break;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (st[i][n - 1] == '.')
        {
            dp[i][n - 1] = 1;
        }
        else
        {
            break;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (st[i][j] == '.')
            {
                dp[i][j] = (dp[i][j + 1] + 0LL + dp[i + 1][j]) % mod;
            }
        }
    }
    cout << dp[0][0] << "\n";

    return 0;
}
