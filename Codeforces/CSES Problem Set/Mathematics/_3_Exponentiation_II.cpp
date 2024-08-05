#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll solve(ll a, ll b, ll mod = 1e9 + 7)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, solve(b, c, mod - 1), mod) << "\n";
    }

    return 0;
}