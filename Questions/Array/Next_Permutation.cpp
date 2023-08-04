#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
// void allPosPermute(vector<int> &a, int idx)
// {
//     if (idx == a.size())
//     {
//         ans.push_back(a);
//         return;
//     }
//     for (int i = idx; i < a.size(); i++)
//     {
//         swap(a[i], a[idx]);
//         allPosPermute(a, idx + 1);
//         swap(a[i], a[idx]);
//     }
//     return;
// }

vector<int> nextPermute(vector<int> &nums)
{
    int idx = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }
    // if (idx == -1)
    // {
    //     reverse(nums.begin(), nums.end());
    //     return nums;
    // }
    for (int i = n - 1; i > idx && idx != -1; i--)
    {
        if (nums[i] > nums[idx])
        {
            swap(nums[i], nums[idx]);
            break;
        }
    }
    reverse(nums.begin() + idx + 1, nums.end());
    return nums;
}

void nextPermuteSTL(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    vector<int> a = {1, 2, 3};
    // for (auto &i : a)
    // {
    //     cin >> i;
    // }
    //----------->>>>>>>>Finding Next permutation
    ans.push_back(nextPermute(a));

    //----------->>>>>>>>Finding all possible permutation
    // allPosPermute(a, 0);

      //----------->>>>>>>>Finding Next permutation using STL

    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}