#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int uniquePaths(vector<vector<int>> &dp, int i, int j, int &n, int &m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || dp[i][j] == -2)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int left = uniquePaths(dp, i, j + 1, n, m);
    int right = uniquePaths(dp, i + 1, j, n, m);
    return dp[i][j] = (left + right * 1LL) % mod;
}

// int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
// {

//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (obstacleGrid[i][j])
//             {
//                 dp[i][j] = -2;
//             }
//         }
//     }
//     return uniquePaths(dp, 0, 0, n, m);
// }

// int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
// {

//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (obstacleGrid[i][j] == 1)
//             {
//                 dp[i][j] = 0;
//             }
//             else if (i == 0 && j == 0)
//             {
//                 dp[i][j] = 1;
//             }
//             else
//             {
//                 int up = 0;
//                 int left = 0;
//                 if (i > 0)
//                 {
//                     up = dp[i - 1][i];
//                 }
//                 if (j > 0)
//                 {
//                     left = dp[i][j - 1];
//                 }
//                 dp[i][j] = up + left;
//             }
//         }
//     }
//     return dp[n - 1][m - 1];
// }
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> pre(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                cur[j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                cur[j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = pre[j];
                }
                if (j > 0)
                {
                    left = cur[j - 1];
                }
                cur[j] = up + left;
            }
        }
        pre = cur;
    }
    return pre[n - 1];
}

int main()
{

    return 0;
}