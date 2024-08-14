#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int left, int right, vector<int> nums, vector<vector<int>> &dp)
    {
        if (left + 1 == right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int ans = 0;
        for (int i = left + 1; i < right; i++)
        {
            int num = nums[left] * nums[i] * nums[right];
            int ret = solve(left, i, nums, dp) + solve(i, right, nums, dp);
            ans = max(ans, num + ret);
        }
        return dp[left][right] = ans;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int length = 2; length <= n + 1; length++)
        {
            for (int left = 0; left <= n + 1 - length; left++)
            {
                int right = left + length;
                for (int i = left + 1; i < right; i++)
                {
                    int num = nums[left] * nums[i] * nums[right];
                    int ret = dp[left][i] + dp[i][right];
                    dp[left][right] = max(dp[left][right], num + ret);
                }
            }
        }

        return dp[0][n + 1];
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    v.insert(v.begin() + 2, 18);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}