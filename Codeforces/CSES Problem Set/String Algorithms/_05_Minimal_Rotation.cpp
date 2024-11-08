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

string least_rotation(string s)
{
    s += s;

    int n = s.size();
    int i = 0;
    int ans = 0;
    while (i < n / 2)
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
            {
                k = i;
                ans = k;
            }
            else
            {
                k++;
            }
            j++;
        }
        while (i <= k)
        {
            i += j - k;
        }
    }
    return s.substr(ans, n / 2);
}

vector<string> duval(string s)
{
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n)
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        // cin >> n;
        string s;
        cin >> s;
        // vector<string> ans = duval(s);
        // for (auto &&i : ans)
        // {
        //     cout << i << "\n";
        // }
        cout << least_rotation(s);
    }

    return 0;
}
