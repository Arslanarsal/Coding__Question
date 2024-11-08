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
vector<pair<int, int>> arr;

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
            cin >> m;
            arr[i] = {m, i + 1};
        }
        sort(arr.begin(), arr.end());
        int i = 0, j = n - 1;
        while (i < j)
        {
            if ((arr[i].first + arr[j].first) == x)
            {
                break;
            }
            if ((arr[i].first + arr[j].first) > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        if (i < j)
        {
            cout << arr[i].second << " " << arr[j].second << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}