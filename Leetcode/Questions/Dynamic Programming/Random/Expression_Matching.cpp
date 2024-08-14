#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(int i, int j, string &s, string &p)
    {
        if (i < 0)
        {
            if (j < 0)
                return true;
            if (p[j] == '*' && j > 0)
                return solve(i, j - 2, s, p);
            return false;
        }
        if (j < 0)
        {
            return false;
        }

        if ((s[i] == p[j] || p[j] == '.') && solve(i - 1, j - 1, s, p))
        {
            return true;
        }
        if (p[j] == '*')
        {
            if (j > 0 && (s[i] == p[j - 1] || p[j - 1] == '.') && solve(i - 1, j, s, p) || (solve(i, j - 2, s, p)))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        return solve(n - 1, m - 1, s, p);
    }
};

int main()
{

    return 0;
}