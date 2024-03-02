#include <bits/stdc++.h>
using namespace std;

int calcGCD(int n, int m)
{
    if (n % m == 0)
    {
        return m;
    }

    return calcGCD(m, n % m);
}

int main()
{

    return 0;
}