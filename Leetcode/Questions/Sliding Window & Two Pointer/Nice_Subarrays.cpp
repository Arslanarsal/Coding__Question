#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        int m = 0;
        int j = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
            {
                m++;
            }
            while (m > k)
            {
                if (nums[j] & 1)
                {
                    m--;
                }
                j++;
            }
            while ( p < n &&  (p < j || !(nums[p] & 1)))
            {
                p++;
            }

            if (m == k)
            {
                cout <<m<<" "<< i << "\n";
                ans = ans + (p - j + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2,2,2,1,2,2,1,2,2,2};
    cout << sol.numberOfSubarrays(v, 2);

    return 0;
}