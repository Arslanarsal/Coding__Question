#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void insert(int arr[], int num)
    {
        for (int i = 0; i < 31; i++)
        {
            if ((num >> i) & 1)
            {
                arr[i]++;
            }
        }
    }

    void numdele(int arr[], int num, int &a)
    {
        for (int i = 0; i < 31; i++)
        {
            if ((num >> i) & 1)
            {
                arr[i]--;
                if (arr[i] == 0)
                {
                    a = a & (~(1 << i));
                }
            }
        }
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int arr[32] = {0};
        int a = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            a = a | nums[i];
            insert(arr, nums[i]);
            while (a >= k)
            {
                ans = min(ans, i - j + 1);
                numdele(arr, nums[j], a);
                j++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    // sol.canSortArray({18, 3, 8});

    return 0;
}