#include <bits/stdc++.h>
using namespace std;

int f(int i, int w, vector<int> &weight, vector<int> &value, int &n, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weight[0] <= w)
        {
            return value[0];
        }
        return 0;
    }

    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int nottake = f(i - 1, w, weight, value, n, dp);
    int take = INT_MIN;
    if (w >= weight[i])
    {
        take = value[i] + f(i - 1, w - weight[i], weight, value, n, dp);
    }
    return dp[i][w] = max(take, nottake);
}

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
//     for (int i = weight[0]; i <= maxWeight; i++)
//     {
//         dp[0][i] = value[0];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int w = 0; w <= maxWeight; w++)
//         {
//             int nottake = dp[i - 1][w];
//             int take = INT_MIN;
//             if (w >= weight[i])
//             {
//                 take = value[i] + dp[i - 1][w - weight[i]];
//             }
//             dp[i][w] = max(take, nottake);
//         }
//     }
//     return dp[n - 1][maxWeight];
// }

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> pre(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        pre[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(maxWeight + 1, 0);
        for (int w = 0; w <= maxWeight; w++)
        {
            int nottake = pre[w];
            int take = INT_MIN;
            if (w >= weight[i])
            {
                take = value[i] + pre[w - weight[i]];
            }
            cur[w] = max(take, nottake);
        }
        pre = cur;
    }
    return pre[maxWeight];
}
int main()
{

    return 0;
}