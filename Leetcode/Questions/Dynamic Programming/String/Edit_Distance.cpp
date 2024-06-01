#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return j;
        }
        if (j == 0)
        {
            return i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (word1[i - 1] != word2[j - 1])
        {
            int ans = INT_MAX;
            ans = min(ans, solve(i - 1, j - 1, word1, word2, dp));
            ans = min(ans, solve(i - 1, j, word1, word2, dp));
            ans = min(ans, solve(i, j - 1, word1, word2, dp));
            return dp[i][j] = ans + 1;
        }
        else
        {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }
    }

public:
    int minDistance(string word1, string word2)
    {

        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(n, m, word1, word2, dp);
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> dp(m + 1, 0);
        vector<int> temp(m + 1, 0);
        for (int i = 0; i <= m; i++)
        {
            dp[i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            temp[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] != word2[j - 1])
                {
                    int ans = INT_MAX;
                    ans = min(ans, dp[j - 1]);
                    ans = min(ans, dp[j]);
                    ans = min(ans, temp[j - 1]);
                    temp[j] = ans + 1;
                }
                else
                {
                    temp[j] = dp[j - 1];
                }
            }
            dp = temp;
        }
        return dp[m];
    }
};

int main()
{

    return 0;
}