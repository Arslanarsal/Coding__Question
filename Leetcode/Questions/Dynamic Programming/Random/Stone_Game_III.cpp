#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, vector<int> &stoneValue, int &n, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int value = stoneValue[i] - solve(i + 1, stoneValue, n, dp);

        if (i + 1 < n)
        {
            int ret = solve(i + 2, stoneValue, n, dp);
            value = max(value, stoneValue[i] + stoneValue[i + 1] - ret);
        }
        if (i + 2 < n)
        {
            int ret = solve(i + 3, stoneValue, n, dp);
            value = max(value, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - ret);
        }
        return dp[i] = value;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {

        int n = stoneValue.size();
        vector<int> dp(3, 0);
        
        // int diff = solve(0, stoneValue, n, dp);
        // if (diff < 0)
        // {
        //     return "Bob";
        // }
        // if (diff > 0)
        // {
        //     return "Alice";
        // }
        // return "Tie";

        for (int i = n - 1; i >= 0; i--)
        {
            int value = stoneValue[i] - dp[0];

            if (i + 1 < n)
            {
                int ret = dp[1];
                value = max(value, stoneValue[i] + stoneValue[i + 1] - ret);
            }
            if (i + 2 < n)
            {
                int ret = dp[2];
                value = max(value, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - ret);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = value;
        }
        int diff = dp[0];
        if (diff < 0)
        {
            return "Bob";
        }
        if (diff > 0)
        {
            return "Alice";
        }
    }
};

int main()
{

    return 0;
}