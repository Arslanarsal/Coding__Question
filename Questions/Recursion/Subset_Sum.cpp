#include <bits/stdc++.h>
using namespace std;

// Number of sequence is (2^n)

// unique elements in array
void subseque(int idx, int temp, vector<int> &arr, vector<int> &ans)
{
    if (idx == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    subseque(idx + 1, temp + arr[idx], arr, ans);
    subseque(idx + 1, temp, arr, ans);
}

vector<int> subsets(vector<int> &num)
{
    vector<int> ans;

    subseque(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {4, 5};
    vector<int> ans = subsets(arr);
    for (auto &&i : ans)
    {

        cout << i << endl;
    }

    return 0;
}