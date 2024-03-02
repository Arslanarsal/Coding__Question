#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    k = (k * l) / nl;
    c = c * d;
    p = p / np;
    int ans = min(k, min(c, p)) / n;
    cout << ans;

    return 0;
}