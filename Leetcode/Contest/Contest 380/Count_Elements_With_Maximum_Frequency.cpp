#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        int ans = 0;
        int mafreq = 0;
        for (int i = 1; i < 100; i++)
        {
            if (nums[i] == mafreq)
            {
                ans += nums[i];
            }
            else if (nums[i] > mafreq)
            {
                ans = nums[i];
                mafreq = nums[i];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}