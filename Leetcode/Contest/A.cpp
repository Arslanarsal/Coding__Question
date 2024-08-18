#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k <= 1)
        {
            return nums;
        }

        vector<int> ans(n - k + 1, -1);
        int i = 0;
        int j = 0;

        while (j < n)
        {
            int m = i + k;
            while (j < n && j < m)
            {
                if (j != i && nums[j - 1] + 1 != nums[j])
                {
                    i = j;
                    m = i + k;
                }
                j++;
            }

            if (i < n - k + 1 && j == m)
            {
                ans[i] = nums[j - 1];
            }

            if (j < n && nums[j - 1] + 1 != nums[j])
            {
                i = j;
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 2};
    int k = 2;
    sol.resultsArray(v, k);
    return 0;
}