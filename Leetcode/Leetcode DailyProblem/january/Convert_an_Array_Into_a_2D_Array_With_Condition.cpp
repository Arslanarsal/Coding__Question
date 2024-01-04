#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<vector<int>> ans;
    unordered_map<int, int> freq;
    for (auto &&el : nums)
    {
        freq[el]++;
        if (ans.size() < freq[el])
        {
            ans.push_back({});
        }
        ans[freq[el] - 1].push_back(el);
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<vector<int>> ans = findMatrix(v);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}