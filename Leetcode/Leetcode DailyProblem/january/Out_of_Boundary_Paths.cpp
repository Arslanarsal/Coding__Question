#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ***dp;
    int mod = 1e9 + 7;
    int solve(int &n, int &m, int &moves, int i, int j, int x)
    {
        if (x > moves)
        {
            return 0;
        }
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return 1;
        }
        if (dp[i][j][x] != -1)
        {
            return dp[i][j][x];
        }
        long long ans = 0;
        (ans += solve(n, m, moves, i + 1, j, x + 1)) % mod;
        (ans += solve(n, m, moves, i - 1, j, x + 1)) % mod;
        (ans += solve(n, m, moves, i, j + 1, x + 1)) % mod;
        (ans += solve(n, m, moves, i, j - 1, x + 1)) % mod;
        return dp[i][j][x] = ans % mod;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        dp = new int **[m];
        for (int i = 0; i < m; i++)
        {
            dp[i] = new int *[n];
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = new int[maxMove + 1];
                memset(dp[i][j], -1, (maxMove + 1) * sizeof(int));
            }
        }
        return solve(m, n, maxMove, startRow, startColumn, 0);
    }
};

int main()
{

    return 0;
}