#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld double

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    vector<ld> r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    // sort(r.begin(), r.end(), greater<>());

    ld expected_inversions = 0.0;

    for (int a = 0; a < n - 1; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            // if (r[a] > r[b])
            // {
            // ld prob = (r[a] - 1) * r[b] / (2.0 * r[a] * r[b]);
            ld prob = (r[a] - 1) / (2 * r[a]);
            expected_inversions += prob;
            // }
        }
    }

    cout << fixed << setprecision(6) << expected_inversions << "\n";
    return 0;
}
