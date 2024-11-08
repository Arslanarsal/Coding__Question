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

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> x;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr.begin(), arr.end());
        for (int m = 0; m < n; m++)
        {
            if (m != 0 && arr[m].first == arr[m - 1].first)
            {
                continue;
            }

            for (int i = m + 1; i < n; i++)
            {

                int j = i + 1;
                int k = n - 1;
                while (j < k)
                {
                    int sum = arr[m].first + arr[i].first + arr[j].first + arr[k].first;
                    if (sum == x)
                    {
                        vector<int> temp = {arr[i].second, arr[m].second, arr[j].second, arr[k].second};
                        sort(temp.begin(), temp.end());
                        for (int i = 0; i < 4; i++)
                        {
                            cout << temp[i] << " ";
                        }
                        return 0;
                    }
                    if (sum < x)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
        }
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}