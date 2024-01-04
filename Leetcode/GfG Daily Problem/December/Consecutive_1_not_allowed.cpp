#include <bits/stdc++.h>
using namespace std;

int countStrings(int n)
{
    long long a = 1;
    long long b = 1;
    long long mod = 1e9 + 7;
    for (int i = 1; i < n; i++)
    {
        long long c = ((a % mod) + (b % mod)) % mod;
        b = a;
        a = c;
    }
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    cout << countStrings(4);

    return 0;
}