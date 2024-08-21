#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;

// int32_t main()
// {
//     fastio;
//     ld n, k;
//     cin >> n >> k;
//     ld ans = 0.0;
//     for (int i = 1; i <= k; i++)
//     {
//         ld p = (i - 1) / k;
//         ans += 1 - pow(p, n);
//     }
//     cout << fixed << setprecision(6) << ans << "\n";
//     return 0;
// }

int32_t main()
{
    fastio;
    int n, k;
    cin >> n >> k;

    ld expected_value = 0.0;

    for (int j = 1; j <= k; j++)
    {
        ld p_j = pow((ld)j / k, n) - pow((ld)(j - 1) / k, n);
        expected_value += j * p_j;
    }

    cout << fixed << setprecision(6) << expected_value << "\n";
    return 0;
}
