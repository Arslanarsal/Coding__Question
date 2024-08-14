#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int N, minP, mod = 1e9 + 7;
    vector<int> g, p;
    int dp[101][101][101];

    int solve(int i, int curg, int curp)
    {
        if (i == g.size())
        {

            if (curp >= minP)
            {
                return 1;
            }
            return 0;
        }

        if (dp[i][curg][curp] != -1)
        {
            return dp[i][curg][curp];
        }

        int pick = 0, notpic = 0;
        notpic = solve(i + 1, curg, curp);
        if (curg + g[i] <= N)
        {
            int nextp = curp;
            if (nextp + p[i] > 100)
            {
                nextp = 100;
            }
            else
            {
                nextp = nextp + p[i];
            }

            pick = solve(i + 1, curg + g[i], nextp);
        }

        return dp[i][curg][curp] = (pick + 0LL + notpic) % mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        N = n;
        minP = minProfit;
        g = group;
        p = profit;
        // memset(dp, -1, sizeof(dp));
        // return solve(0, 0, 0);

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < 101; i++)
        {
            for (int j = minProfit; j < 101; j++)
            {
                dp[g.size()][i][j] = 1;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int curg = n; curg >= 0; curg--)
            {
                for (int curp = minProfit; curp >= 0; curp--)
                {
                    int pick = 0, notpic = 0;
                    notpic = dp[i + 1][curg][curp];
                    if (curg + g[i] <= N)
                    {
                        int nextp = curp;
                        if (nextp + p[i] > 100)
                        {
                            nextp = 100;
                        }
                        else
                        {
                            nextp = nextp + p[i];
                        }

                        pick = dp[i + 1][curg + g[i]][nextp];
                    }

                    dp[i][curg][curp] = (pick + 0LL + notpic) % mod;
                }
            }
        }
        return dp[0][0][0];
    }
};

int main()
{
    Solution sol;
    int n = 5, minProfit = 3;
    vector<int> group = {2, 2}, profit = {2, 3};
    sol.profitableSchemes(n, minProfit, group, profit);

    return 0;
}