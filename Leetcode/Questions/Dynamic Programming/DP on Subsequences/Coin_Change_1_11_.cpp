#include <bits/stdc++.h>
using namespace std;

// Coin change 1;

// class Solution
// {
//     int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp)
//     {
//         if (dp[i][amount] != -1)
//         {
//             return dp[i][amount];
//         }
//         if (i == 0)
//         {
//             if (amount % coins[i] == 0)
//             {
//                 return amount / coins[i];
//             }
//             return 1e9;
//         }
//         int nottake = solve(i - 1, coins, amount, dp);
//         int take = 1e9;
//         if (coins[i] <= amount)
//         {
//             take = solve(i, coins, amount - coins[i], dp) + 1;
//         }

//         return dp[i][amount] = min(take, nottake);
//     }

// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         if (!amount)
//         {
//             return 0;
//         }

//         int n = coins.size();
//         // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         // int ans = solve(n - 1, coins, amount, dp);
//         // return ans == 1e9 ? -1 : ans;

//         vector<int> pre(amount + 1, 0);
//         for (int i = 0; i <= amount; i++)
//         {
//             if (i % coins[0] == 0)
//             {
//                 pre[i] = i / coins[0];
//             }
//             else
//             {
//                 pre[i] = 1e9;
//             }
//         }

//         for (int i = 1; i < n; i++)
//         {
//             vector<int> temp(amount + 1, 0);
//             for (int t = 0; t <= amount; t++)
//             {
//                 int nottake =pre[t];
//                 int take = 1e9;
//                 if (coins[i] <= t)
//                 {
//                     take = temp[t - coins[i]] + 1;
//                 }
//                 temp[t] = min(take, nottake);
//             }
//             pre = temp;
//         }
//         int ans = pre[amount];
//         if (ans >= 1e9)
//         {
//             return -1;
//         }
//         return ans;
//     }
// };

// Coin change 2;
class Solution
{
    int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        if (i == 0)
        {
            if (amount % coins[i] == 0)
            {
                return 1;
            }
            return 0;
        }
        int nottake = solve(i - 1, coins, amount, dp);
        int take = 0;
        if (coins[i] <= amount)
        {
            take = solve(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount] = take + nottake;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        if (!amount)
        {
            return 1;
        }
        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // int ans = solve(n - 1, coins, amount, dp);
        // return ans;

        vector<int> pre(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                pre[i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> temp(amount + 1, 0);
            for (int t = 0; t <= amount; t++)
            {
                int nottake = pre[t];
                int take = 0;
                if (coins[i] <= t)
                {
                    take = temp[t - coins[i]];
                }
                temp[t] = (take + nottake);
            }
            pre = temp;
        }
        int ans = pre[amount];

        return ans;
    }
};

int main()
{

    return 0;
}