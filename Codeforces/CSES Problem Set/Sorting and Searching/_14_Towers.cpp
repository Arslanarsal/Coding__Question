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
int t, n, q, m, x;
vector<int> arr, ans;
int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;

    while (t--)
    {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int idx = upper_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            if (idx == ans.size())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans[idx] = arr[i];
            }
            // cout << idx << " ";
        }
        cout << ans.size() << "\n";
    }

    return 0;
}