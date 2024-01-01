#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int minPathSum(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int &n, int &m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return INT_MAX;
        }
        if (i == n - 1 && j == m - 1)
        {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = minPathSum(grid, dp, i, j + 1, n, m);
        int down = minPathSum(grid, dp, i + 1, j, n, m);
        return dp[i][j] = (grid[i][j] + min(down, right));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minPathSum(grid, dp, 0, 0, n, m);
    }
};

// int minPathSum(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i == 0 && j == 0)
//             {
//                 dp[i][j] = grid[i][j];
//             }
//             else
//             {
//                 int up = INT_MAX;
//                 int left = INT_MAX;
//                 if (i > 0)
//                 {
//                     up = dp[i - 1][j];
//                 }
//                 if (j > 0)
//                 {
//                     left = dp[i][j - 1];
//                 }
//                 dp[i][j] = grid[i][j] + min(up, left);
//             }
//         }
//     }
//     return dp[n-1][m-1];
// }

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0){}
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                {
                    up = grid[i - 1][j];
                }
                if (j > 0)
                {
                    left = grid[i][j - 1];
                }
                grid[i][j] += min(up, left);
            }
        }
    }
    return grid[n - 1][m - 1];
}

int main()
{

    return 0;
}