#include <bits/stdc++.h>
using namespace std;

class Solution
{
    set<vector<int>> ans;
    void solve(int i, vector<int> &candidates, int target, vector<int> &temp, int tempsum)
    {
        if (i == candidates.size())
        {
            if (tempsum == target)
            {
                vector<int> s = temp;
                sort(s.begin(), s.end());
                ans.insert(s);
            }
            return;
        }

        solve(i + 1, candidates, target, temp, tempsum);
        if (tempsum + candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target, temp, tempsum + candidates[i]);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> t;
        solve(0, candidates, target, t, 0);
        vector<vector<int>> res;
        for (auto &&i : ans)
        {
            res.push_back(i);
        }
        return res;
    }
};

int main()
{

    return 0;
}