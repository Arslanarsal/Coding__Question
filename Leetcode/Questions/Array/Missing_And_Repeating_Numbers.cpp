#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        s2 += (a[i] * 1LL * a[i]);
    }
    long long val1 = s - sn; // x-y
    long long val2 = s2 - s2n;

    val2 = val2 / val1; // x+y

    long long x = (val1 + val2) / 2;
    long long y = val2 - x;
    return {(int)x, (int)y};
}

int main()
{

    return 0;
}