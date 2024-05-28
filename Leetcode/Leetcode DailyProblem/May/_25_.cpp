#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(string s, vector<string> &wordDict, unordered_set<string> &st, string temp, vector<string> &ans, int idx, int &n)
    {
        if (idx >= n)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            string str = s.substr(idx, i - idx + 1);
            if (st.count(str))
            {
                if (i == n - 1)
                {
                    solve(s, wordDict, st, temp + str, ans, i + 1, n);
                }
                else
                {
                    solve(s, wordDict, st, temp + str + " ", ans, i + 1, n);
                }
            }
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st;
        for (auto &&i : wordDict)
        {
            st.insert(i);
        }
        vector<string> ans;
        int n = s.size();
        solve(s, wordDict, st, "", ans, 0, n);
        return ans;
    }
};

int main()
{
    string s = "catsanddog";
    vector<string> words = {"cat", "cats", "and", "sand", "dog"};
    Solution sol;
    sol.wordBreak(s, words);

    return 0;
}