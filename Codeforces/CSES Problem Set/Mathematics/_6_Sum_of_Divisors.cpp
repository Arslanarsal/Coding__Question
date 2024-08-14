#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long mod = 1e9 + 7;
ll TWO_MOD_INV = 1;

// long long sum_all_divisors(long long num)
// {
//     long long sum = 0;
//     for (long long i = 1; i * i <= num; i++)
//     {
//         long long t1 = i * ((num / i) - (i + 1));
//         long long t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2);
//         sum += t1 + t2;
//     }
//     return sum;
// }

void solve()
{
    ll b = mod - 2;
    ll a = 2;
    while (b)
    {
        if (b & 1)
        {
            TWO_MOD_INV = (TWO_MOD_INV * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
}

ll sum(ll start, ll end)
{
    return (((end - start + 1) % mod) * ((start + end) % mod) % mod) * TWO_MOD_INV % mod;
}

ll sum_all_divisors(ll num)
{
    ll sumOfDivisor = 0;
    ll first = 1;

    while (first <= num)
    {
        ll block = num / first;
        ll last = num / block;
        ll sumRange = sum(first, last);
        sumOfDivisor = (sumOfDivisor + (sumRange * (block % mod)) % mod) % mod;
        first = last + 1;
    }

    return sumOfDivisor;
}

int main()
{
    solve();
    ll n;
    cin >> n;
    int sum = sum_all_divisors(n);
    cout << sum << '\n';
    return 0;
}
