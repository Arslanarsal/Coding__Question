#include <bits/stdc++.h>
using namespace std;

// int f(int i, int w, vector<int> &weight, vector<int> &value, int &n, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         if (weight[0] <= w)
//         {
//             return value[0];
//         }
//         return 0;
//     }

//     if (dp[i][w] != -1)
//     {
//         return dp[i][w];
//     }
//     int nottake = f(i - 1, w, weight, value, n, dp);
//     int take = INT_MIN;
//     if (w >= weight[i])
//     {
//         take = value[i] + f(i - 1, w - weight[i], weight, value, n, dp);
//     }
//     return dp[i][w] = max(take, nottake);
// }

// // int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// // {
// //     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
// //     for (int i = weight[0]; i <= maxWeight; i++)
// //     {
// //         dp[0][i] = value[0];
// //     }

// //     for (int i = 1; i < n; i++)
// //     {
// //         for (int w = 0; w <= maxWeight; w++)
// //         {
// //             int nottake = dp[i - 1][w];
// //             int take = INT_MIN;
// //             if (w >= weight[i])
// //             {
// //                 take = value[i] + dp[i - 1][w - weight[i]];
// //             }
// //             dp[i][w] = max(take, nottake);
// //         }
// //     }
// //     return dp[n - 1][maxWeight];
// // }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     vector<int> pre(maxWeight + 1, 0);
//     for (int i = weight[0]; i <= maxWeight; i++)
//     {
//         pre[i] = value[0];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         vector<int> cur(maxWeight + 1, 0);
//         for (int w = 0; w <= maxWeight; w++)
//         {
//             int nottake = pre[w];
//             int take = INT_MIN;
//             if (w >= weight[i])
//             {
//                 take = value[i] + pre[w - weight[i]];
//             }
//             cur[w] = max(take, nottake);
//         }
//         pre = cur;
//     }
//     return pre[maxWeight];
// }

class Solution
{
    int solve(int i, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (dp[i][W] != -1)
        {
            return dp[i][W];
        }

        if (i == 0)
        {
            if (W >= wt[i])
            {
                return (W / wt[i]) * val[i];
            }
            return 0;
        }
        int nottake = solve(i - 1, W, val, wt, dp);
        int take = 0;
        if (W >= wt[i])
        {
            take = val[i] + solve(i, W - wt[i], val, wt, dp);
        }
        return dp[i][W] = max(take, nottake);
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        // return solve(N - 1, W, val, wt, dp);
        vector<int> pre(W + 1, 0);
        for (int w = wt[0]; w <= W; w++)
        {
            pre[w] = (w / wt[0]) * val[0];
        }
        for (int i = 1; i < N; i++)
        {

            for (int w = 0; w <= W; w++)
            {
                int nottake = pre[w];
                int take = 0;
                if (w >= wt[i])
                {
                    take = val[i] + pre[w - wt[i]];
                }
                pre[w] = max(take, nottake);
            }
        }
        return pre[W];
    }
};

int main()
{

    return 0;
}