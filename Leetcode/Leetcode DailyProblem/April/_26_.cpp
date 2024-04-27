#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int minFallingPathSum(vector<vector<int>> &grid, int cur, int pre, vector<vector<int>> &dp)
    {
        if (cur == grid.size() - 1)
        {
            int res = INT_MAX;
            for (int i = 0; i < grid[0].size(); i++)
            {
                if (i != pre)
                {
                    res = min(grid[cur][i], res);
                }
            }
            return dp[cur][pre + 1] = res;
        }
        if (dp[cur][pre + 1] != -1)
        {
            return dp[cur][pre + 1];
        }

        int res = INT_MAX;
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (pre == -1 || pre != i)
            {
                int temp = grid[cur][i] + minFallingPathSum(grid, cur + 1, i, dp);
                res = min(res, temp);
            }
        }
        return dp[cur][pre + 1] = res;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, (vector<int>(m, -1)));
        return minFallingPathSum(grid, 0, -1, dp);
    }
};

int main()
{

    return 0;
}