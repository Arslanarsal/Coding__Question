#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solveop(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int o = j + 1; o < m; o++)
        {
            int k = grid[i][o] - grid[i][j];
            dp[i][j] = max(dp[i][j], max(k + dp[i][o], k));
        }
        for (int o = i + 1; o < n; o++)
        {
            int k = grid[o][j] - grid[i][j];
            dp[i][j] = max(dp[i][j], max(k + dp[o][j], k));
        }
        return;
    }

    int solvedp(vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (j != m - 1)
                {
                    int k = grid[n - 1][j] - grid[n - 1][i];
                    dp[n - 1][i] = max(dp[n - 1][i], max(k + dp[n - 1][j], k));
                }
                else
                {
                    int k = grid[n - 1][j] - grid[n - 1][i];
                    dp[n - 1][i] = max(dp[n - 1][i], k);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (j != n - 1)
                {
                    int k = grid[j][m - 1] - grid[i][m - 1];
                    dp[i][m - 1] = max(dp[i][m - 1], max(k + dp[j][m - 1], k));
                }
                else
                {
                    int k = grid[j][m - 1] - grid[i][m - 1];
                    dp[i][m - 1] = max(dp[i][m - 1], k);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                solveop(grid, dp, i, j);
            }
        }
        int ans = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
        {
            ans = max(ans, dp[i][m - 1]);
        }
        for (int i = m - 2; i >= 0; i--)
        {
            ans = max(ans, dp[n - 1][i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }

public:
    int maxScore(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return solvedp(grid, dp);
    }
};

int maxScore(vector<vector<int>> &A)
{
    int res = -1e6, m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int pre = min(i > 0 ? A[i - 1][j] : 1e6, j > 0 ? A[i][j - 1] : 1e6);
            res = max(res, A[i][j] - pre);
            A[i][j] = min(A[i][j], pre);
            cout << A[i][j] << "|" << res << "  ||  ";
        }
        cout << endl;
    }

    return res;
}

int main()
{
    vector<vector<int>> v = {{9, 5, 7, 3}, {8, 9, 6, 1}, {6, 7, 14, 3}, {2, 5, 3, 1}};
    maxScore(v);

    return 0;
}