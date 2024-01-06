#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getAns(vector<int> arr, int n, int ind, int prev_index, vector<vector<int>> &dp)
    {
        // Base condition
        if (ind == n)
            return 0;

        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];

        int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

        int take = 0;

        if (prev_index == -1 || arr[ind] > arr[prev_index])
        {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }

        return dp[ind][prev_index + 1] = max(notTake, take);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getAns(nums, n, 0, -1, dp);
    }
};

int main()
{

    return 0;
}