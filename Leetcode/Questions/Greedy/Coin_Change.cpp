#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int n)
{
    int dp[++n];
    dp[0] = 0;
    sort(begin(coins), end(coins));
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int c : coins)
        {
            if (i - c < 0)
                break;
            if (dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    return dp[--n] == INT_MAX ? -1 : dp[n];
}





/*
    Time Complexity: O(1)
    Space Complexity: O(N)

    where 'N' is the given amount to be changed.
*/

vector<int> MinimumCoins(int n)
{
    // Array to store denominations.
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int m = denominations.size();

    // Pick coins in decreasing order of their values.
    for (int i = m - 1; i >= 0; i--)
    {
        while (n >= denominations[i])
        {
            n = n - denominations[i];
            ans.push_back(denominations[i]);
        }
    }

    return ans;
}

int main()
{
    vector<int> ans = MinimumCoins(13);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}