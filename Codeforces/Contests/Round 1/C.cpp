#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll ans = 0;
        ll last = 0;
        for (int i = 1; i < n; i++)
        {
            ll v1 = v[i - 1], v2 = v[i];
            ll c1 = 0, c2 = 0;

            if (v2 == 1 && v1 > 1)
            {
                ans = -1;
                break;
            }

            while (v2 < v1)
            {
                v2 *= v2;
                c2++;
            }

            while (v1 * v1 <= v2)
            {
                if (v1 == 1)
                {
                    break;
                    c1 = -1;
                }

                v1 *= v1;
                c1++;
            }

            if (c2)
            {
                last += c2;
            }
            else if (c1 == -1)
            {
                last = 0;
            }
            else
            {
                last = max(0LL, last - c1);
            }
            ans += last;
        }
        cout << ans << "\n";
    }

    return 0;
}