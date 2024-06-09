#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 0;
        int rem = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            rem = (rem + (nums[i] % k)) % k;
            if (mp.count(rem))
            {
                if (mp[rem] != i)
                {
                    return true;
                }
            }
            else
            {
                mp[rem] = i + 1;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}