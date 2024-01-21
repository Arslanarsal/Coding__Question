#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArrayLength(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int el = nums[0];
        int minval = nums[0];
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el)
            {
                cnt++;
            }
            if (nums[i] % el != 0)
            {
                minval = min(minval, nums[i] % el);
            }
        }
        if (minval != el || cnt == 1)
        {
            return 1;
        }
        return (cnt + 1) / 2;
    }
};

int main()
{

    return 0;
}