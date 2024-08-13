#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 1e9 + 7;
;
vector<vector<int>> dp(N, vector<int>(2, 0));

int main()
{

    dp[1][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i < N; i++)
    {
        dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (4LL * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + 0LL + dp[n][1]) % mod << "\n";
    }

    return 0;
}