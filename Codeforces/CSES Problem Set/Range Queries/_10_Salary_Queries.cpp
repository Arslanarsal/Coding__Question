#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given the address at index] |==| [order_of_key ==> Number of element smaller then X]
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q;

int32_t main()
{
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        oSet st(arr.begin() + 1, arr.end());
        while (q--)
        {
            char ch;
            int a, b;
            cin >> ch;
            cin >> a >> b;
            if (ch == '?')
            {
                int start = st.order_of_key(a);
                int end = st.order_of_key(b + 1);
                cout << end - start << "\n";
            }
            else
            {
                int idx = st.order_of_key(arr[a]);
                auto it = st.find_by_order(idx);
                st.erase(it);
                arr[a] = b;
                st.insert(b);
            }
        }
    }

    return 0;
}
