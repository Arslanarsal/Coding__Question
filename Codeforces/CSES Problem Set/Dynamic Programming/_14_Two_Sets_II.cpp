#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7, mod2 = 500000004;
int n, totalsum, half;
vector<vector<int>> dp;

int solve(int i, int sum)
{
    if (i > n)
    {
        return sum == half;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    int pick = 0;
    int ans = solve(i + 1, sum);
    if ((sum + i) <= half)
    {
        pick = solve(i + 1, sum + i);
    }

    dp[i][sum] = (ans + pick) % mod;
    return dp[i][sum];
}

int bin(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (a * ans) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int32_t main()
{

    cin >> n;
    totalsum = (n * (n + 1)) / 2;
    half = totalsum / 2;
    dp.resize(n + 1, vector<int>(half + 1, -1));
    if (totalsum & 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    int result = solve(1, 0);
    cout << ((result % mod) * mod2) % mod << "\n";
    return 0;
}