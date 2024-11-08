#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x, k;

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> arr(n), ans(n - k + 1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        oSet st;
        for (int i = 0; i < k; i++)
        {
            st.insert(arr[i]);
        }

        int mid = *st.find_by_order((k - 1) / 2);
        int val = 0;
        for (int i = 0; i < k; i++)
        {
            val = val + abs(mid - arr[i]);
        }
        ans[0] = val;
        int last_mid = mid;
        for (int i = k; i < n; i++)
        {
            int idx = st.order_of_key(arr[i - k]);
            st.erase(st.find_by_order(idx));
            st.insert(arr[i]);
            mid = *st.find_by_order((k - 1) / 2);
            val = val + abs(arr[i] - mid) - abs(last_mid - arr[i - k]);
            if (!(k & 1))
            {
                val -= mid - last_mid;
            }
            last_mid = mid;
            ans[i - k + 1] = val;
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
