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
int t, n, q;

vector<int> z_function(string &s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int32_t main()
{
    t = 1;
    // cin >> t;
    while (t--)
    {
        // cin >> n;
        string s;
        cin >> s;
        n = s.size();
        vector<int> ans = z_function(s);
        // for (auto &&it : ans)
        // {
        //     cout << it << " ";
        // }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] + i == n)
            {
                cout << i << " ";
            }
        }
        cout << n << "\n";
    }

    return 0;
}
