#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<long long> subarray;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == 0)
                {
                    subarray.push_back(prefix[j]);
                }
                else
                {
                    subarray.push_back(prefix[j] - prefix[i - 1]);
                }
            }
        }
        sort(subarray.begin(), subarray.end());
        long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = left - 1; i < right; i++)
        {
            ans = (ans + subarray[i]) % mod;
        }
        return ans;
    }
};

int main()
{

    return 0;
}