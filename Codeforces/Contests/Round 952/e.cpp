#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, z, k;
        cin >> x >> y >> z >> k;
        long long ans = 0;
        for (long long i = 1; i <= x; i++)
        {
            for (long long j = 1; j <= y; j++)
            {
                long long c = k % (i * j);
                long long l = k / (i * j);
                if (c == 0 && l <= z)
                {
                    long long temp = (x - i + 1) * (y - j + 1) * (z - l + 1);
                    ans = max(ans, temp);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}