#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, m, q, x, k;

int32_t main()
{
    fastio;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int ans = (k + 1) / 2;
        if (!(n & 1))
        {
            ans--;
            if ((k + 1) & 1)
            {
                ans++;
            }
        }
        if (ans & 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}
