#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

// Mathematical functions
long long mod_sub(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
long long powermod(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, k;
        cin >> l >> r >> k;
        if (k >= 10)
        {
            cout << 0 << endl;
        }
        else if (k >= 5)
        {
            long long ls = powermod(2, l, M); // log(l)
            long long rs = powermod(2, r, M); // log(r)
            cout << mod_sub(rs, ls, M) << endl;
        }
        else if (k == 4)
        {
            long long ls = powermod(3, l, M);
            long long rs = powermod(3, r, M);
            cout << mod_sub(rs, ls, M) << endl;
        }
        else if (k == 3)
        {
            long long ls = powermod(4, l, M);
            long long rs = powermod(4, r, M);
            cout << mod_sub(rs, ls, M) << endl;
        }
        else if (k == 2)
        {
            long long ls = powermod(5, l, M);
            long long rs = powermod(5, r, M);
            cout << mod_sub(rs, ls, M) << endl;
        }
        else
        {
            long long ls = powermod(10, l, M);
            long long rs = powermod(10, r, M);
            cout << mod_sub(rs, ls, M) << endl;
        }
    }
    return 0;
}

// TC - log(r)
// SC - O(1)