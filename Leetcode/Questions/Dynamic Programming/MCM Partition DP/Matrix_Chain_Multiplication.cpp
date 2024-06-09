#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int j, int *arr, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(int n, int arr[])
    {

        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return f(1, n - 1, arr, dp);
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 1; j < n; j++)
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};

int main()
{

    return 0;
}