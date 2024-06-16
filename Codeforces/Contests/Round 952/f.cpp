#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long h, n;
        cin >> h >> n;
        vector<long long> d(n);
        vector<long long> c(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> d[i];
            h -= d[i];
        }

        for (long long i = 0; i < n; i++)
            cin >> c[i];

        if (h <= 0)
        {
            cout << 1 << "\n";
            continue;
        }
        long long l = 0, r = 1e18;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = (l + r) >> 1;
            long long s = 0;  // Use __int128 to avoid overflow
            for (long long i = 0; i < n; i++)
            {
                long long term = (long long)(mid / c[i]) * d[i];
                s += term;
                if (s > h)
                {
                    break;  // Early exit to prevent overflow
                }
            }
            if (h - s <= 0)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans + 1 << "\n";
    }

    return 0;
}
