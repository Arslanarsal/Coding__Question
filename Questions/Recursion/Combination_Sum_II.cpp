#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int target, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    if (target==0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {

        if (i > idx && nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] > target)
        {
           break;
        }
        temp.push_back(nums[i]);
        solve(i + 1, target - nums[i], nums, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, target, candidates, temp, ans);
    return ans;
}

int main()
{
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = combinationSum2(v, 8);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}