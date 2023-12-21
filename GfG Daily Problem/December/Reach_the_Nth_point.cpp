#include <bits/stdc++.h>
using namespace std;

int nthPoint(int n)
{
    int a = 1;
    int b = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int c = (a * 1LL + b) % mod;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    cout << nthPoint(5);

    return 0;
}