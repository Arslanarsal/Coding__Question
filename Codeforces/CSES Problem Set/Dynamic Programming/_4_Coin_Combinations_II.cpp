#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll solve(ll N, ll X, vector<ll> &coins)
{
    vector<ll> dp(X + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i]; j <= X; j++)
        {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }
    return dp[X];
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    cout << solve(n, k, inp);

    return 0;
}