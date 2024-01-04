#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int f(int i, int d, vector<int> &job, vector<vector<int>> &dp)
    {
        if (d == 1)
        {
            int ans = INT_MIN;
            for (int j = i; j < n; j++)
            {
                ans = max(ans, job[j]);
            }
            return ans;
        }
        if (dp[i][d] != -1)
        {
            return dp[i][d];
        }
        int ans = INT_MAX;
        int max_value = INT_MIN;
        for (int j = i; j <= n - d; j++)
        {
            max_value = max(max_value, job[j]);
            ans = min(ans, max_value + f(j + 1, d - 1, job, dp));
        }
        return dp[i][d] = ans;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return f(0, d, jobDifficulty, dp);
    }
};

int main()
{

    return 0;
}