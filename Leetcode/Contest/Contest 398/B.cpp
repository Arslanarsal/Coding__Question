#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> pre(n, 0);
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1];
            if ((nums[i] & 1) == (nums[i - 1] & 1))
            {
                pre[i]++;
            }
        }
        int m = queries.size();
        vector<bool> ans(m, true);
        if (n == 1)
        {
            return ans;
        }
        for (int i = 0; i < m; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            if (pre[v] - pre[u])
            {
                ans[i] = false;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}