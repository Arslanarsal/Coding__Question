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

void solveLPS(string &p, vector<int> &lps)
{
    lps[0] = 0;
    int n = p.size();
    int i = 1, len = 0;
    while (i < n)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
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
        vector<int> lps(n);
        solveLPS(s, lps);
        // for (auto &&it : lps)
        // {
        //     cout << it << " ";
        // }
        vector<int> ans;
        int i = lps[n - 1];
        while (i > 0)
        {
            ans.push_back(i);
            i = lps[i - 1];
        }
        sort(ans.begin(), ans.end());
        for (auto &&i : ans)
        {
            cout << i << " ";
        }
    }

    return 0;
}