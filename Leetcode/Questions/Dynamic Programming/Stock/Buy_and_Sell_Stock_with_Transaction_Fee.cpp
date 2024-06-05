#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n)
    {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0)
    { // We can buy the stock
        profit = max(getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    // Create a DP table to memoize results
    // vector<vector<long>> dp(n, vector<long>(2, -1));
    // return getAns(Arr, 0, 0, n, dp);

    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            long profit = 0;
            if (buy == 0)
            { // We can buy the stock
                profit = max(dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }
            if (buy == 1)
            { // We can sell the stock
                profit = max(dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][1];
}

class Solution
{
    int F;
    long getAns(int ind, int buy, vector<int> &Arr, int n, vector<vector<long>> &dp)
    {
        // Base case: When we reach the end of the array, there are no more decisions to make.
        if (ind == n)
        {
            return 0;
        }

        // If the result for this state has already been calculated, return it
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }

        long profit = 0;

        if (buy == 0)
        { // We can buy the stock
            profit = max(getAns(ind + 1, 0, Arr, n, dp), -Arr[ind] + getAns(ind + 1, 1, Arr, n, dp));
        }

        if (buy == 1)
        { // We can sell the stock
            profit = max(getAns(ind + 1, 1, Arr, n, dp), Arr[ind] - F + getAns(ind + 1, 0, Arr, n, dp));
        }

        // Store the calculated profit in the DP table and return it
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        F = fee;
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        // Create a DP table to memoize results
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return getAns(0, 0, prices, n, dp);
    }
};


int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
