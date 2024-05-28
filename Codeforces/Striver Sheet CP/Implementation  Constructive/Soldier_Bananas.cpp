#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, n, w;
    cin >> k >> n >> w;
    long long ans = (k * ((w * (w + 1)) / 2)) - n;
    if (ans > 0)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }

    return 0;
}