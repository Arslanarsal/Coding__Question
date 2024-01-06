#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int, int> mp;
        for (auto &&num : nums)
        {
            mp[num]++;
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }
        while (mp.find(sum) != mp.end())
        {
            sum++;
        }
        return sum;
    }
};

int main()
{

    return 0;
}