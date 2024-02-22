#include <bits/stdc++.h>
using namespace std;

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

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixChainMultiplication(int *arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(1, n, arr, dp);
}

int main()
{

    return 0;
}