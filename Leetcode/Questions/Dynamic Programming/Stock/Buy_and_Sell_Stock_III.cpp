#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long getAns(int ind, int buy, int t, int n, vector<int> &Arr, vector<vector<vector<long>>> &dp)
    {
        // Base case: When we reach the end of the array, there are no more decisions to make.
        if (ind == n)
        {
            return 0;
        }

        // If the result for this state has already been calculated, return it
        if (dp[ind][buy][t] != -1)
        {
            return dp[ind][buy][t];
        }

        long profit = 0;

        if (t < 2 && buy == 0)
        { // We can buy the stock
            profit = max(getAns(ind + 1, 0, t, n, Arr, dp), -Arr[ind] + getAns(ind + 1, 1, t + 1, n, Arr, dp));
        }

        if (buy == 1)
        { // We can sell the stock
            profit = max(getAns(ind + 1, 1, t, n, Arr, dp), Arr[ind] + getAns(ind + 1, 0, t, n, Arr, dp));
        }

        // Store the calculated profit in the DP table and return it
        return dp[ind][buy][t] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        // Create a DP table to memoize results
        vector<vector<long>> next(2, vector<long>(3, 0));
        vector<vector<long>> temp(2, vector<long>(3, 0));
        // return getAns(0, 0, 0, n, prices, dp);
        
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int t = 0; t < 3; t++)
                {
                    long profit = 0;

                    if (t < 2 && buy == 0)
                    { // We can buy the stock
                        profit = max(next[0][t], -prices[ind] + next[1][t + 1]);
                    }

                    if (buy == 1)
                    { // We can sell the stock
                        profit = max(next[1][t], prices[ind] + next[0][t]);
                    }

                    // Store the calculated profit in the DP table and return it
                     temp[buy][t] = profit;
                }
            }
            next = temp;
        }
        return next[0][0];
    }
};

int main()
{

    return 0;
}