#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = solve(i - 1, j, s, t, dp);
        if (s[i] == t[j])
        {
            ans += solve(i - 1, j - 1, s, t, dp);
        }
        return dp[i][j] = ans;
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, s, t, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        // dp[0][0] = s[0] == t[0];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int ans = dp[i - 1][j];
                if (s[i] == t[j])
                {
                    ans += dp[i - 1][j - 1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};

int main()
{

    return 0;
}