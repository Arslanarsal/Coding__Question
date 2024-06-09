#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mixi = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int step = (nums[i - 1] * nums[k] * nums[j + 1]) + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            mixi = max(step, mixi);
        }
        return dp[i][j] = mixi;
    }

public:
    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        // return solve(1, n, nums, dp);
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                {
                    continue;
                }
                int mixi = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    int step = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                    mixi = max(step, mixi);
                }
                dp[i][j] = mixi;
            }
        }
        return dp[1][n];
    }
};

int main()
{

    return 0;
}