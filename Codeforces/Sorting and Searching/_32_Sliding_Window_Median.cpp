#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        oSet st;
        for (int i = 0; i < k; i++)
        {
            st.insert(arr[i]);
        }
        vector<int> ans(n - k + 1);
        ans[0] = *st.find_by_order((k - 1) / 2);
        for (int i = k; i < n; i++)
        {
            int num = arr[i - k];
            int index = st.order_of_key(num);
            st.erase(st.find_by_order(index));
            st.insert(arr[i]);
            ans[i - k + 1] = *st.find_by_order((k - 1) / 2);
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}