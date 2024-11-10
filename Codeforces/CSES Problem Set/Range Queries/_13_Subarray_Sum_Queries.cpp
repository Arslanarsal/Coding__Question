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
int t, n, m, q, x;
const int N = 2e5 + 2;
int seg[4 * N][4];
/*
0 -> max_Element
1 -> prefix_Sum
2 -> Surfix_Sum
3 -> Total_Sum
*/

void insert_val(int idx, int val)
{
    idx += x;
    for (int i = 0; i < 4; i++)
    {
        seg[idx][i] = val;
    }
    idx = idx >> 1;
    while (idx)
    {
        seg[idx][0] = max({seg[idx * 2][0], seg[idx * 2 + 1][0], seg[idx * 2][2] + seg[idx * 2 + 1][1], 0LL});
        seg[idx][1] = max({seg[idx * 2][1], seg[idx * 2][3] + seg[idx * 2 + 1][1], 0LL});
        seg[idx][2] = max({seg[idx * 2 + 1][2], seg[idx * 2][2] + seg[idx * 2 + 1][3], 0LL});
        seg[idx][3] = seg[idx * 2][3] + seg[idx * 2 + 1][3];
        idx >>= 1;
    }
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> q;
        x = pow(2, ceil(log2(n)));
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            insert_val(i, value);
        }
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            a--;
            insert_val(a, b);
            int ans = seg[1][0];
            if (ans < 0)
            {
                ans = 0;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
