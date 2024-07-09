#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define p first;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll ans;
        if (y > x)
        {
            if (y & 1)
            {
                ans = y * y - x + 1;
            }
            else
            {
                ans = (y - 1) * (y - 1) + x;
            }
        }
        else
        {
            if (x & 1)
            {
                ans = (x - 1) * (x - 1) + y;
            }
            else
            {
                ans = x * x - y + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}