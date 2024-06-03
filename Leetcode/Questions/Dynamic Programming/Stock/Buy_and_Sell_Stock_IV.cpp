#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        // Create a DP table to memoize results
        vector<vector<long>> next(2, vector<long>(k+1, 0));
        vector<vector<long>> temp(2, vector<long>(k+1, 0));
       
        
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int t = 0; t < k+1; t++)
                {
                    long profit = 0;

                    if (t < k && buy == 0)
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