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
int dp[1001][1 << 11];
void generate_mask(int mask, int cur_maks, int i, int n, vector<int> &masks)
{
    if (i == n + 1)
    {
        masks.push_back(cur_maks);
        return;
    }
    if (mask & (1 << i))
        generate_mask(mask, cur_maks, i + 1, n, masks);

    if ((i != n) && ((mask & (1 << i)) == 0) && ((mask & (1 << (i + 1))) == 0))
        generate_mask(mask, cur_maks, i + 2, n, masks);

    if ((mask & (1 << i)) == 0)
        generate_mask(mask, cur_maks + (1 << i), i + 1, n, masks);
}

int solve(int i, int n, int m, int cur_mask)
{
    if (i == m + 1)
        return cur_mask == 0;

    if (dp[i][cur_mask] != -1)
        return dp[i][cur_mask];

    vector<int> masks;
    generate_mask(cur_mask, 0, 1, n, masks);
    int ans = 0;
    for (auto &&mask : masks)
        ans = (ans + solve(i + 1, n, m, mask)) % mod;

    return dp[i][cur_mask] = ans;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, n, m, 0) << "\n";
    }

    return 0;
}