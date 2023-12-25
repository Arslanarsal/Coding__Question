#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> &dp, int i, int j, int &n, int &m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
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
    return dp[i][j] = left + right;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return uniquePaths(dp, 0, 0, n, m);
}

/*
    Time Complexity  : O(M * N)
    Space Complexity : O(M * N)

    Where 'M' is the number of rows and 'N' is the number of columns of the matrix.
*/

int uniquePaths(int m, int n)
{
    // Reference table to store subproblems.
    int dp[m][n];

    // Paths to reach a cell in column 1.
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }

    // Paths to reach a cell in row 1.
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }

    // Bottom up approach.
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // Returning answer.
    return dp[m - 1][n - 1];
}


int uniquePaths(int m, int n)
{
    // Reference array to store subproblems.
    int dp[n] = {1};

    // Bottom up approach.
    dp[0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }

    // Returning answer.
    return dp[n - 1];
}

int main()
{
    cout << uniquePaths(3, 2);

    return 0;
}
