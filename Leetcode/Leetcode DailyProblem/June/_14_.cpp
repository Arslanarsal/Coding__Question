#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int diff = nums[i - 1] - nums[i] + 1;
                ans += diff;
                nums[i] += diff;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}