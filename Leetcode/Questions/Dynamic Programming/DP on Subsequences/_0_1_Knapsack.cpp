#include <bits/stdc++.h>
using namespace std;

int f(int i, int w, vector<int> &weight, vector<int> &value, int &n, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int nottake = f(i + 1, w, weight, value, n, dp);
    int take = INT_MIN;
    if (w >= weight[i])
    {
        take = f(i + 1, w - weight[i], weight, value, n, dp) + value[i];
    }
    return dp[i][w] = max(take, nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    return f(0, maxWeight, weight, value, n, dp);
}
int main()
{

    return 0;
}