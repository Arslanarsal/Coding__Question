#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet;
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, m, q, x;
int a, b;
int32_t main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;

        int ans = 0, temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == 0 && temp)
            {
                ans++;
                temp--;
            }
            if (a >= x)
            {
                temp += a;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
