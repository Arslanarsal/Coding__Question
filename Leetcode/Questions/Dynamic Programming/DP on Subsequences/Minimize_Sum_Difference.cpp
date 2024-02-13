#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mindiff(vector<int> &nums, int arr1, int arr2, int i, int n, int x, int y, vector<vector<vector<int>>> &dp)
    {
        if (i > nums.size() || x > n / 2 || y > n / 2)
        {
            return INT_MAX;
        }
        if (x == n / 2 && y == n / 2 && i == nums.size())
        {
            return abs(arr1 - arr2);
        }
        if (dp[i][x][y] != -1)
        {
            return dp[i][x][y];
        }

        int temp1 = mindiff(nums, arr1 + nums[i], arr2, i + 1, n, x + 1, y, dp);
        int temp2 = mindiff(nums, arr1, arr2 + nums[i], i + 1, n, x, y + 1, dp);
        return dp[i][x][y] = min(temp1, temp2);
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n / 2 + 1, vector<int>(n / 2 + 1, -1)));
        return mindiff(nums, 0, 0, 0, n, 0, 0, dp);
    }
};

int main()
{

    return 0;
}