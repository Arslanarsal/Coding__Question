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
    vector<pair<int, int>> arr;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> m >> x;
            arr.push_back({m, x});
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int ans = 0;
        while (i < n)
        {
            int start = arr[i].first;
            int end = arr[i].second;
            i++;
            while (i < n && arr[i].first < end && arr[i].second > end)
            {
                i++;
            }

            if (i < n && arr[i].first >= end)
            {
                ans++;
            }
        }
        cout << ans + 1 << "\n";
    }

    return 0;
}