#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> inp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    vector<long long> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inp[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - inp[j]] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dp[x] << "\n";
    }
    return 0;
}
