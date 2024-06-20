#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dp;
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ret = solve(n - 1, dp);
        if (!(n & 1))
        {
            ret = min(ret, solve(n / 2, dp));
        }
        if (n % 3 == 0)
        {
            ret = min(ret, solve(n - (2 * (n / 3)), dp));
        }
        return dp[n] = ret + 1;
    }

public:
    int minDays(int n)
    {
        dp.resize(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        // return solve(n, dp);
        for (int i = 2; i <= n; i++)
        {
            int ret = dp[i - 1];
            if (!(i & 1))
            {
                ret = min(ret, dp[i / 2]);
            }
            if (i % 3 == 0)
            {
                ret = min(ret, dp[i - (2 * (i / 3))]);
            }
            dp[i] = ret + 1;
        }
        return dp[n];
    }
};
class Solution {
public:
unordered_map<int, int> dp;
int minDays(int n) {
    if (n <= 1)
        return n;
    if (dp.count(n) == 0)
        dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
    return dp[n];
}
};
int main()
{

    return 0;
}