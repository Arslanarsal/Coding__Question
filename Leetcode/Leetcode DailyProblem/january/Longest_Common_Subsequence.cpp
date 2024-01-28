#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i] == b[j])
        {
            return dp[i][j] = 1 + solve(i - 1, j - 1, a, b, dp);
        }
        return dp[i][j] = max(solve(i, j - 1, a, b, dp), solve(i - 1, j, a, b, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, text1, text2, dp);
    }
};

int main()
{

    return 0;
}