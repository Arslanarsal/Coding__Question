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

class Solution
{
public:
    int atMostK(string s, int k)
    {
        if (k < 0)
            return 0;

        int i = 0, j = 0, cnt = 0;
        int res = 0;
        int m[26] = {0};

        while (j < s.length())
        {
            m[s[j] - 'a']++;
            if (m[s[j] - 'a'] == 1)
                cnt++;

            if (cnt > k)
            {
                m[s[i] - 'a']--;
                if (m[s[i] - 'a'] == 0)
                    cnt--;
                i++;
            }
            if (cnt <= k)
            {
                res += (j - i + 1);
            }
            j++;
        }
        return res;
    }

    int countSubstr(string str, int k) { return atMostK(str, k) - atMostK(str, k - 1); }
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
    }

    return 0;
}