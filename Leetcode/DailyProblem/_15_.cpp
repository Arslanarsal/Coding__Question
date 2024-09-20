#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void mancher(string &s, vector<int> &b)
    {
        string t = "#";
        for (auto &&i : s)
        {
            t += i;
            t += "#";
        }
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i < r)
            {
                b[i] = max(0, min(r - i, b[l + r - i]));
            }
            while (i - b[i] >= 0 && b[i] + i < (n * 2 + 1) && t[b[i] + i] == t[i - b[i]])
            {
                b[i]++;
            }
            b[i]--;
            if (i + b[i] > r)
            {
                r = i + b[i];
                l = i - b[i];
            }
        }
    }

public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        vector<int> b(n + 1, 0);
        mancher(s, b);
        int maxlen = 1;
        for (int i = 0; i <= n; i++)
        {
            if ((i / 2 - b[i] / 2) == 0)
            {
                maxlen = b[i];
            }
        }
        string temp = s.substr(maxlen);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
};

int main()
{
    Solution sol;
    sol.shortestPalindrome("abcd");
    return 0;
}