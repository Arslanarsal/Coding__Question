#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
#define pii pair<int, int>
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].left;
            cin >> arr[i].right;
            arr[i].index = i;
        }
        vector<int> contain(n, 0), contained(n, 0);
        oSet st;
        sort(arr.begin(), arr.end(), [&](range a, range b)
             {
    if (a.left == b.left)
        return a.right > b.right;  
    return a.left < b.left; });

        for (int i = 0; i < n; i++)
        {
            st.insert({arr[i].right, -1 * i});
            contained[arr[i].index] = st.size() - st.order_of_key({arr[i].right, -1 * i}) - 1;
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            st.insert({arr[i].right, -1 * i});
            contain[arr[i].index] = st.order_of_key({arr[i].right, -1 * i});
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