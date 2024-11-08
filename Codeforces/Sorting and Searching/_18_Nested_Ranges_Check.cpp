#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet;
// [find_by_order ==> given address at index] |==| [order_of_key ==> Number of elements smaller than X]
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x;

struct range
{
    int left, right, index;
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        vector<range> arr(n);
        vector<bool> contain(n, 0), contained(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].left;
            cin >> arr[i].right;
            arr[i].index = i;
        }

        // Sort ranges: first by left ascending, then by right descending
        sort(arr.begin(), arr.end(), [&](range a, range b)
             {
            if (a.left == b.left) {
                return a.right > b.right;
            }
            return a.left < b.left; });

        // Check for contained intervals
        int maxend = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].right <= maxend)
            {
                contained[arr[i].index] = true;
            }
            maxend = max(maxend, arr[i].right);
        }

        
        int minend = LLONG_MAX; 
        for (int i = n - 1; i >= 0; i--)
        { 
            if (arr[i].right >= minend)
            {
                contain[arr[i].index] = true;
            }
            minend = min(minend, arr[i].right);
        }

        for (int i = 0; i < n; i++)
        {
            cout << contain[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << contained[i] << " ";
        }
    }

    return 0;
}
