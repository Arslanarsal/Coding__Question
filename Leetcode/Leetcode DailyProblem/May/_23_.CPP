#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int ans = 0;
    void solve(int i, vector<int> &nums, int &k, unordered_map<int, int> &mp)
    {
        if (i == nums.size())
        {
            ans++;
            return;
        }
        solve(i + 1, nums, k, mp);
        if (!mp[nums[i] - k] && !mp[nums[i] - k])
        {
            mp[nums[i]]++;
            solve(i + 1, nums, k, mp);
            mp[nums[i]]--;
        }
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        solve(0, nums, k, mp);
        return ans - 1;
    }
};

int main()
{

    return 0;
}