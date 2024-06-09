#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool ispaldrmic(int i, int j, string s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int idx, string s, vector<int> &dp)
    {
        if (idx == s.size())
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int ans = INT_MAX;
        for (int i = idx; i < s.size(); i++)
        {
            if (ispaldrmic(idx, i, s))
            {
                ans = min(ans, 1 + solve(i + 1, s, dp));
            }
        }
        return dp[idx] = ans;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // return solve(0, s, dp) - 1;
        for (int idx = n; idx >= 0; idx--)
        {
            int ans = INT_MAX;
            for (int i = idx; i < n; i++)
            {
                if (ispaldrmic(idx, i, s))
                {
                    ans = min(ans, 1 + dp[i + 1]);
                }
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}