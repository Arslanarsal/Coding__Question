#include <bits/stdc++.h>
using namespace std;

int f(int i, int w, int v, vector<int> &weight, vector<int> &value, int &n, vector<vector<vector<int>>> &dp)
{
    if (w == 0)
        return v;
    if (i == n - 1)
    {
        if (w >= weight[i])
        {
            return v + value[i];
        }
        return v;
    }

    if (dp[i][w][v] != -1)
    {
        return dp[i][w][v];
    }
    int nottake = f(i + 1, w, v, weight, value, n, dp);
    int take = INT_MIN;
    if (w >= weight[i])
    {
        take = f(i + 1, w - weight[i], v + value[i], weight, value, n, dp);
    }
    return dp[i][w][v] = max(take, nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int maxv = 0;
    for (auto &&i : value)
    {
        maxv += i;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxWeight + 1, vector<int>(maxv + 1, -1)));

    return f(0, maxWeight, 0, weight, value, n, dp);
}
int main()
{

    return 0;
}