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
int t, n, q, m, x, a, b;
int dp[20][11][2][2];

int solve(string &s, int i, int pre, bool leading_zero, bool tight)
{
    if (i == 0)
        return 1;

    if (dp[i][pre + 1][leading_zero][tight] != -1)
        return dp[i][pre + 1][leading_zero][tight];

    int lo = 0;
    int hi = tight ? (s[s.size() - i] - '0') : 9;
    int ans = 0;
    for (int lo = 0; lo <= hi; ++lo)
    {
        if (lo == pre && !leading_zero)
            continue;
        ans += solve(s, i - 1, lo, leading_zero && (lo == 0), tight && (lo == hi));
    }
    return dp[i][pre + 1][leading_zero][tight] = ans;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> a >> b;
        string A = to_string(a - 1);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(A, A.size(), -1, 1, 1);

        string B = to_string(b);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(B, B.size(), -1, 1, 1);
        cout << ans2 - ans1 << "\n";
    }

    return 0;
}