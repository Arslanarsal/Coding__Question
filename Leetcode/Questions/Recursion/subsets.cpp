#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void bsetsWithDup(int i, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans)
    {

        // Method 1
        // if (i >= nums.size())
        // {
        //     ans.push_back(temp);
        //     return;
        // }
        // temp.push_back(nums[i]);
        // bsetsWithDup(i + 1, nums, temp, ans);
        // temp.pop_back();
        // bsetsWithDup(i + 1, nums, temp, ans);

        // Method 2
        ans.push_back(temp);
        for (int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[j]);
            bsetsWithDup(j + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        bsetsWithDup(0, nums, temp, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].size() == 0)
            {
                cout << "[]";
            }

            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3};
    sol.subsetsWithDup(v);

    return 0;
}