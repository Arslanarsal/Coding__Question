#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = INT_MIN;
    int solve(int i, int j, int &k, int &m, int &n, vector<int> &subarraysum)
    {
        if (i >= n)
        {
            if (j == k)
            {
                return 0;
            }
            return -1e8;
        }
        if (j == k)
        {
            return 0;
        }
        int sum = solve(i + 1, j, k, m, n, subarraysum);
        if ((i + m) < n)
        {
            int temp = subarraysum[i + m] + solve(i + m, j + 1, k, m, n, subarraysum);
            sum = max(sum, temp);
        }
        return sum;
    }

public:
    int maxSum(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        vector<int> subarraysum(n - m + 1);
        for (int i = 0; i < m; i++)
        {
            subarraysum[0] += nums[i];
        }
        int presum = subarraysum[0];
        for (int i = m; i < n; i++)
        {
            presum -= nums[i - m];
            presum += nums[i];
            subarraysum[i - m + 1] = presum;
        }
        int l = subarraysum.size();
        return solve(0, 0, k, m, l, subarraysum);
    }
};

int32_t main()
{

    return 0;
}