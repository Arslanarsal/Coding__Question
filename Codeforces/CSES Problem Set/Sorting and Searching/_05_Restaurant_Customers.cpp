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
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x;

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> m >> x;
            mp[m]++;
            mp[x]--;
        }
        int ans = 0, temp = 0;
        for (auto &&it : mp)
        {
            temp += it.second;
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }

    return 0;
}