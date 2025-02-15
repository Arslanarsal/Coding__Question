#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]
#define int long long
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
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        int left = 0;
        map<int, int> mp;
        int distinctCount = 0;

        for (int right = 0; right < n; right++)
        {
      
            mp[arr[right]]++;
            if (mp[arr[right]] == 1) // New distinct element
                distinctCount++;

            // Shrink the window if the number of distinct elements exceeds x
            while (distinctCount > x)
            {
                mp[arr[left]]--;
                if (mp[arr[left]] == 0) // Distinct element removed
                    distinctCount--;
                left++;
            }

            if (distinctCount <= x)
            {
                ans += right - left + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
