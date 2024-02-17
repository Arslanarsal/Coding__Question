#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool f(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (i == nums.size() - 1)
        {
            return nums[i] == target;
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        if (f(i + 1, target, nums, dp))
        {
            return dp[i][target] = true;
        }
        else if (target >= nums[i] && f(i + 1, target - nums[i], nums, dp))
        {
            return dp[i][target] = true;
        }
        return dp[i][target] = false;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum1 = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum1 += nums[i];
        }
        if (sum1 & 1)
        {
            return false;
        }
        sum1 = sum1 / 2;
        vector<vector<int>> dp(n+1, vector<int>(sum1+1, -1));
        return f(0, sum1, nums, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 3, 3, 4, 5};
    cout << sol.canPartition(v);

    return 0;
}