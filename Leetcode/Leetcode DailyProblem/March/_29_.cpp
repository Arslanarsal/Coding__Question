#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxele = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> ind;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxele)
            {
                ind.push_back(i);
            }
            if (ind.size() - 1 == k)
            {
                int last_ind = ind[ind.size() - k];
                ans = ans + last_ind + 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}