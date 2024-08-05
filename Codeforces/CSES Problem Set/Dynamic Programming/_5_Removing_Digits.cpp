#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 10)
    {
        cout << 1 << "\n";
        return 0;
    }
    vector<int> dp(n + 1);
    for (int i = 0; i < 10; i++)
    {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++)
    {
        int temp = i;
        int minval = INT_MAX;
        while (temp > 0)
        {
            int digit = temp % 10;
            temp /= 10;
            if (digit)
            {
                minval = min(minval, dp[i - digit]);
            }
        }
        dp[i] = minval + 1;
    }

    cout << dp[n] << "\n";

    return 0;
}