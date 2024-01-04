#include <bits/stdc++.h>
using namespace std;

// Number of sequence is (2^n)

// unique elements in array
void subseque(int idx, vector<int> &temp, vector<int> &arr, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    temp.push_back(arr[idx]);
    subseque(idx + 1, temp, arr, ans); // Pick one
    temp.pop_back();
    subseque(idx + 1, temp, arr, ans); // Not pick one
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    subseque(0, temp, nums, ans);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = subsets(arr);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}