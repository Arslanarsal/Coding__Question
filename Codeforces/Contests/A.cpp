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

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
<<<<<<< HEAD
        cin >> n;
=======
        string s, t;
        cin >> s >> t;
        n = s.size();
        m = t.size();
        int ans = n + m;
        int i = 0;
        int j = 0;
        while (i < n && j < m && s[i] == t[j])
        {
            i++;
            j++;
        }
        i = (i != 0) ? i - 1 : i;
        ans = ans - i;
        cout << ans << "\n";
>>>>>>> cfc39bffb3206a568c012c1c993005a6947778bf
    }

    return 0;
}
