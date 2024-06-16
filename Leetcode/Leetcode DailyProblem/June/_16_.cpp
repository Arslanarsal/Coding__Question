#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int m = nums.size();
        int maxele = 0;
        int i = 0;
        int ans = 0;
        while (maxele < n)
        {
            if (i < m && nums[i] <= maxele + 1)
            {
                maxele += nums[i];
                i++;
            }
            else
            {
                maxele += maxele + 1;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}