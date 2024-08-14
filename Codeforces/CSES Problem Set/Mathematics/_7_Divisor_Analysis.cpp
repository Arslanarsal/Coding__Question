#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int pows(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

int powe(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Function to find modular multiplicative inverse of a under modulo mod
int modInverse(int a)
{
    return powe(a, mod - 2);
}

int32_t main()
{
    int n, number = 1;
    cin >> n;
    vector<pair<int, int>> v(n);
    int noOfDivisior = 1, sumOfDivisior = 1, productOfDivisior = 1;

    for (int i = 0; i < n; i++)
    {
        int x, k;
        cin >> x >> k;
        v[i] = {x, k};
        noOfDivisior = (noOfDivisior * (k + 1)) % mod;
    }

    for (int i = 0; i < n; i++)
    {
        int p = v[i].first;
        int m = v[i].second;
        number = (number * pows(p, m));
    }

    for (int i = 0; i < n; i++)
    {
        int p = v[i].first;
        int m = v[i].second;
        int term = (powe(p, m + 1) - 1 + mod) % mod;
        term = (term * modInverse(p - 1)) % mod;
        sumOfDivisior = (sumOfDivisior * term) % mod;
    }

    if (noOfDivisior & 1)
    {
        int p = pows(number, (mod - 1) / 2);
        productOfDivisior = powe(p, noOfDivisior);
    }
    else
    {
        productOfDivisior = powe(number, noOfDivisior / 2);
    }

    cout << noOfDivisior << "\n";
    cout << sumOfDivisior << "\n";
    cout << productOfDivisior << "\n";

    return 0;
}
