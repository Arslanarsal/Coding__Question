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
vector<int> arr;

bool solve(int mid)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += mid / arr[i];
        if (ans >= x)
        {
            return true;
        }
    }
    return ans >= x;
}
int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> x;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int low = 0, high = 1e18;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (solve(mid))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}