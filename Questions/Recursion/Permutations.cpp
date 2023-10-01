#include <bits/stdc++.h>
using namespace std;

//Here add permutation add in another vcetor ds
void recurpermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!(freq[i]))
        {
            ds.push_back(nums[i]);
            freq[i] = true;
            recurpermute(ds, nums, ans, freq);
            freq[i] = false;
            ds.pop_back();
        }
    }
}

//Here Simple swap the value and print it
void solvee(vector<int> &nums, vector<vector<int>> &ans, int idx)
{
    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        solvee(nums, ans, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;

    // vector<int> ds;
    // int freq[nums.size()] = {0};
    // recurpermute(ds, nums, ans, freq);

    solvee(nums, ans, 0);

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans = permute(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << " ";
    }

    return 0;
}