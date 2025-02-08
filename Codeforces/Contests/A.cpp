#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;

int32_t main()
{
    fastio;
    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int prey = 0, prex = 0;
        int ans = 0;
        bool flag = false;
        while (n--)
        {
            int y, x;
            cin >> y >> x;
            ans += (m * 4);
            if (flag)
            {
                ans -= (2 * ((m - x) + (m - y)));
            }
            flag = true;
        }
        cout << ans << "\n";
    }

    return 0;
}