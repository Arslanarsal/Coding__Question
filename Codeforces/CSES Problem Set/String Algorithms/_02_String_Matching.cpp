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
                // len--;
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
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        // cin >> n;
        string s, p;
        cin >> s >> p;
        int ans = 0;
        n = p.size();
        int m = s.size();
        vector<int> lps(n, 0);
        solveLPS(p, lps);
        int i = 0; // pointer for s
        int j = 0; // pointer for p
        while (i < m)
        {
            if (s[i] == p[j])
            {
                i++;
                j++;
            }

            if (j == n)
            {
                ans++;
                j = lps[j - 1];
            }
            else if (i < m && s[i] != p[j])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
