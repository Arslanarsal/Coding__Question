#include <bits/stdc++.h>
using namespace std;

int f(int idx, int k, vector<int> &height, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int minstep = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            int s = f(idx - i, k, height, dp) + abs(height[idx] - height[idx - i]);
            minstep = min(minstep, s);
        }
    }
    return dp[idx] = minstep;
}
int f(int idx, int k, vector<int> &height, vector<int> &dp)
{
    if (idx <= 1)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int minstep = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 1)
        {
            int s = f(idx - i, k, height, dp) + abs(height[idx - 1] - height[idx - 1 - i]);
            minstep = min(minstep, s);
        }
    }
    dp[idx] = minstep;
    return minstep;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    return f(n, k, height, dp);
}

int main()
{

    return 0;
}