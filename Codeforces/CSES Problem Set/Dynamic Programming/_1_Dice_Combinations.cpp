#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                dp[i] = (0LL + dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n] << "\n";
}

// from k to n
void solve2(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= n - i)
            {
                dp[i] = (0LL + dp[i] + dp[i + j]) % mod;
            }
        }
    }
    cout << dp[0] << "\n";
}

int main()
{
    int n;
    cin >> n;
    // solve(n);

    return 0;
}