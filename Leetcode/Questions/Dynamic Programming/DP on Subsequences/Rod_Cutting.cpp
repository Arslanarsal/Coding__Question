#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int ind, int n, int pricce[], vector<vector<int>> &dp)
    {

        if (ind == 0)
            return pricce[0] * n;

        if (dp[ind][n] != -1)
            return dp[ind][n];

        int notake = solve(ind - 1, n, pricce, dp);
        int take = INT_MIN;
        int rodlength = ind + 1;
        if (rodlength <= n)
        {
            take = pricce[ind] + solve(ind, n - rodlength, pricce, dp);
        }
        return dp[ind][n] = max(take, notake);
    }

public:
    int cutRod(int price[], int n)
    {
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(n - 1, n, price, dp);
      vector<int> pre(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
           pre[i] = i * price[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int i = 0; i <= n; i++)
            {
                int notake = pre[i];
                int take = INT_MIN;
                int rodlength = ind + 1;
                if (rodlength <= i)
                {
                    take = price[ind] + pre[i - rodlength];
                }
                 pre[i] = max(take, notake);
            }
      
        }
        return pre[n];
    }
};

int main()
{

    return 0;
}