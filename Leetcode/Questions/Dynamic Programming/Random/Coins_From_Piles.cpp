#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    int solve(int i, int k, vector<vector<int>> &piles)
    {
        if (k == 0 || i >= piles.size())
        {
            return 0;
        }

        if (dp[i][k] != -1)
        {
            return dp[i][k];
        }

        int notpick = solve(i + 1, k, piles);
        int pick = 0, currentSum = 0;

        for (int j = 0; j < min((int)piles[i].size(), k); j++)
        {
            currentSum += piles[i][j];
            pick = max(pick, currentSum + solve(i + 1, k - j - 1, piles));
        }

        return dp[i][k] = max(pick, notpick);
    }

public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, piles);
    }
};

int main()
{

    return 0;
}