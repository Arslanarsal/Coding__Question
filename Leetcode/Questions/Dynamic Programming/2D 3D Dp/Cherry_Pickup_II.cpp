#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return -1;
        }
        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        int ans = 0;
        for (int k = -1; k < 2; k++)
        {
            for (int z = -1; z < 2; z++)
            {
                if (j1 == j2)
                {
                    ans = max(ans, grid[i][j1] + f(i + 1, j1 + k, j2 + z, grid, n, m, dp));
                }
                else
                {
                    ans = max(ans, grid[i][j2] + grid[i][j1] + f(i + 1, j1 + k, j2 + z, grid, n, m, dp));
                }
            }
        }
        return dp[i][j1][j2] = ans;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, n, m, dp);
    }
};

int main()
{

    return 0;
}