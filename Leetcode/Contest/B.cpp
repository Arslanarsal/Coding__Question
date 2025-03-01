#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> lps(string &p)
    {
        int n = p.size();
        vector<int> ans(n, 0);
        int i = 1, j = 0;
        while (i < n)
        {
            if (p[i] == p[j])
            {
                ans[i] = j + 1;
                i++;
                j++;
            }
            else if (j)
            {
                j = ans[j - 1];
            }
            else
            {
                ans[i] = 0;
                i++;
            }
        }
        return ans;
    }

    void solve(string &s, string &p, vector<int> &lps, vector<int> &ans)
    {

        int n = s.size();
        int m = p.size();
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = i;
            }
            return;
        }

        int i = 0, j = 0;
        while (i < n)
        {
            if (s[i] == p[j])
            {
                i++;
                j++;
            }
            else if (j)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }

            if (j == m)
            {
                ans[i - 1] = i - 1;
                j = lps[j - 1];
            }
        }
    }

public:
    int shortestMatchingSubstring(string s, string p)
    {
        int n = s.size();
        vector<int> point;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                point.push_back(i);
            }
        }

        string one = s.substr(0, point[0]);
        string two = s.substr(point[0] + 1, point[1] - point[0] - 1);
        string third = s.substr(point[1] + 1);

        vector<int> onelps = lps(one);
        vector<int> twolps = lps(two);
        vector<int> thirdlps = lps(third);

        vector<int> temp3(n, -1);
        solve(s, third, thirdlps, temp3);

        vector<int> temp2(n, -1);
        solve(s, two, twolps, temp2);

        for (int i = n - 2; i >= 0; i--)
        {
            if (temp3[i] == -1 && temp3[i + 1] != -1)
            {
                temp3[i] = temp3[i + 1];
            }
            if (temp2[i] == -1 && temp2[i + 1] != -1)
            {
                temp2[i] = temp2[i + 1];
            }
        }

        vector<int> temp1(n, -1);
        solve(s, one, onelps, temp1);

        int res = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (temp1[i] != -1)
            {
                if (i + two.size() < n && temp2[i + two.size()] != -1)
                {
                    int secondStart = temp2[i + two.size()];
                    if (secondStart + third.size() < n && temp3[secondStart + third.size()] != -1)
                    {
                        int matchLength = (temp3[secondStart + third.size()] - i) + one.size();
                        res = min(res, matchLength);
                    }
                }
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};

int32_t main()
{

    return 0;
}