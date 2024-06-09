#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> nums)
    {
        vector<int> lis(n, 1);
        /* Compute LIS values from left to right */
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] and lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1; // updating LIS value for current index

        vector<int> lds(n, 1);
        /* Compute LDS values from right to left */
        for (int i = n - 2; i >= 0; i--)
            for (int j = n - 1; j > i; j--)
                if (nums[i] > nums[j] and lds[i] < lds[j] + 1)
                    lds[i] = lds[j] + 1; // updating LDS value for current index

        /* Return the maximum value of lis[i] + lds[i] - 1*/
        int ans = 0; // initializing ans with length of longest bitonic sequence
        for (int i = 1; i < n - 1; i++)
            if (lis[i] > 1 && lds[i] > 1)
            {
                ans = max(ans, lis[i] + lds[i] - 1); // updating ans if current index has non-zero values for both LIS and LDS
            }
        return ans;
    }
};

int main()
{

    return 0;
}