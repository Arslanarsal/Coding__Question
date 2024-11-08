#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> ans(n);
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp ^= nums[i];
        }
        int k = pow(2, maximumBit) - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int num = k;
            for (int j = 0; j < maximumBit; j++)
            {
                if ((temp >> j) & 1)
                {
                    num = num & (~(1 << j));
                }
                else
                {
                    num = num | (1 << j);
                }
            }
            ans[n - i - 1] = num;
            temp ^= nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // sol.canSortArray({18, 3, 8});

    return 0;
}