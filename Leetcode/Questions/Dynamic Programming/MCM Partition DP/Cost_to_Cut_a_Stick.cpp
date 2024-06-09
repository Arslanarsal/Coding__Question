#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = 1e9;
        for (int k = i; k <= j; k++)
        {
            int step = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, step);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        // return f(1, c, cuts, dp);
        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i > j)
                {
                    continue;
                }
                
                int mini = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int step = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, step);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};

int main()
{

    return 0;
}