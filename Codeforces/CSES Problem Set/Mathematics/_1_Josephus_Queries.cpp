#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    return ((solve(n - 1, k) + k ) % n) ;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) + 1 << "\n";

        // vector<int> dp(n + 1, 0);
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++)
        // {
        //     dp[i] = (dp[i - 1] + k) % i;
        //     if (dp[i] == 0)
        //         dp[i] = i; // Adjust for 1-based indexing
        // }
        // cout << dp[n] << "\n";
    }

    return 0;
}
