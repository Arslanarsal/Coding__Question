#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool check(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        int n = s1.size();
        int m = s2.size();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i] || s1[n - i - 1] != s2[m - i - 1])
            {
                return false;
            }
        }
        
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(words[i], words[j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> v = {"pa", "papa", "ma", "mama"};
    // vector<string> v = {"a", "abb"};
    cout << sol.countPrefixSuffixPairs(v);

    return 0;
}