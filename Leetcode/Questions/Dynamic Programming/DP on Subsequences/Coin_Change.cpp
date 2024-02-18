#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (coins[i] == amount)
        {
            return 1;
        }
        if (i == 0)
        {
            int take = -1;
            if (amount >= coins[i])
            {
                take = f(i, amount - coins[i], coins, dp);
            }
            if (take == -1)
            {
                return -1;
            }

            return 1 + take;
        }
        if (dp[i][amount] != -1)
        {
            return dp[i][amount];
        }

        int nottake = f(i - 1, amount, coins, dp);
        int take = -1;
        if (amount >= coins[i])
        {
            take = f(i, amount - coins[i], coins, dp);
        }
        if (take == -1 && nottake == -1)
        {
            return dp[i][amount] = -1;
        }
        if (take != -1 && nottake != -1)
        {
            return dp[i][amount] = 1 + min(nottake, take);
        }
        if (take == -1)
        {
            return dp[i][amount] = 1 + nottake;
        }
        return dp[i][amount] = 1 + take;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (!amount)
        {
            return 0;
        }
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(coins.size() - 1, amount, coins, dp);
    }
};

int main()
{

    return 0;
}