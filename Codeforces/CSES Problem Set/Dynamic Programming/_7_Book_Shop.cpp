#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp)
{
    if (j == 0)
    {
        return 0;
    }
    if (i == price.size() - 1)
    {
        if (j >= price[i])
        {
            return pages[i];
        }
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int notpick = solve(i + 1, j, price, pages, dp);

    if (j >= price[i])
    {
        notpick = max(notpick, (pages[i] + solve(i + 1, j - price[i], price, pages, dp)));
    }

    return dp[i][j] = notpick;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // cout << solve(0, x, price, pages, dp);

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = price[n - 1]; i <= x; i++)
    {
        dp[n - 1][i] = pages[n - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= x; j++)
        {
            int notpick = dp[i + 1][j];

            if (j >= price[i])
            {
                notpick = max(notpick, (pages[i] + dp[i + 1][j - price[i]]));
            }

            dp[i][j] = notpick;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << dp[0][x];

    return 0;
}