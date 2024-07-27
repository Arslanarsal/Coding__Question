#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            string str = to_string(nums[i]);
            int z = nums[i];
            int placeval = 1;
            int newint = 0;
            if (z < 10)
            {
                newint = mapping[z];
                z = 0;
            }
            while (z)
            {

                int rem = z % 10;
                z /= 10;
                newint = newint + (mapping[rem] * placeval);
                placeval *= 10;
            }

            v.push_back({newint, i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[v[i].second];
        }
        return ans;
    }
};

int main()
{

    return 0;
}