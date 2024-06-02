#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j == 0)
        {
            return 1;
        }
        if (i == 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i - 1] == t[j - 1])
        {
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        }
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(n, m, s, t, dp);
        vector<double> pre(m + 1, 0);

        pre[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    pre[j] = pre[j - 1] + pre[j];
                }
            }
        }
        return (int)pre[m];
    }
};

int main()
{

    return 0;
}