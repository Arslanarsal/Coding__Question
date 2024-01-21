#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        int l1 = max(nums[1], nums[2]);
        int l2 = min(nums[1], nums[2]);
        for (int i = 3; i < n; i++)
        {
            if (nums[i] < l1 && nums[i] < l2)
            {
                cout << nums[i] << " ";
                l1 = l2;
                l2 = nums[i];
            }
            else if (nums[i] < l1 && nums[i] >= l2)
            {
                l1 = nums[i];
            }
        }
        return nums[0] + l1 + l2;
    }
};

int main()
{

    Solution sol;
    vector<int> v = {1, 6, 49, 35, 41, 4, 31, 39, 36, 39};
    cout << endl
         << sol.minimumCost(v);
    return 0;
}