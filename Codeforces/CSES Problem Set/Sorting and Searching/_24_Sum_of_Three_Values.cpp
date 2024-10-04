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
int t, n, m, q, x;

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
        map<int, int> mp;
        set<int> st;
        vector<int> temp = {-1, -1, -1};
        int i = 0, j = n - 1;
        while (i < j)
        {
            int sum = x - (arr[i].first + arr[j].first);
            if (st.count(sum))
            {
                temp[0] = arr[i].second;
                temp[1] = arr[j].second;
                temp[2] = mp[x];
                break;
            }
            if (x < 0)
            {
                st.insert(arr[j].first);
                mp[arr[j].first] = arr[j].second;
                j--;
            }
            else
            {
                st.insert(arr[i].first);
                mp[arr[i].first] = arr[i].second;
                i++;
            }
        }
        if (temp[0] == -1)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            sort(temp.begin(), temp.end());
            cout << temp[0] << " " << temp[1] << " " << temp[2] << "\n";
        }
    }

    return 0;
}
