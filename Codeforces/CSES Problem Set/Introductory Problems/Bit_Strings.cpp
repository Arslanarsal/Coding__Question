#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
long long binExpIte(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    cout << binExpIte(2, n) << "\n";

    return 0;
}