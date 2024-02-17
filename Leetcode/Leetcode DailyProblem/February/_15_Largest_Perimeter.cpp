#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int presum = nums[0] + nums[1];
        int ans = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (presum > nums[i])
            {
                ans = max(ans, presum + nums[i]);
            }
            presum += nums[i];
        }
        return ans == 0 ? -1 : ans;
    }
};

int main()
{

    return 0;
}