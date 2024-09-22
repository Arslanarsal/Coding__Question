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
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> k;

        oSet st;
        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
        }
        int idx = 0;

        m = st.size();
        while (m)
        {
            idx = idx % m;
            idx = (idx + k) % m;
            auto it = st.find_by_order(idx);
            cout << *it << " ";
            st.erase(it);
            m = st.size();
        }
    }

    return 0;
}
