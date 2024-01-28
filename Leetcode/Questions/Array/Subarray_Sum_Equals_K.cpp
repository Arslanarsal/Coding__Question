#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        int presum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            presum = nums[i];
            int remove = presum - k;
            cnt += mp[remove];
            mp[presum] += 1;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}