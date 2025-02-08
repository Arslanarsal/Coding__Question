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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;

class Solution
{
public:
    int dp[50009][29][4];
    string answer = "";

    int solve(int i, int j, int c, string &s)
    {
        if (i == s.size())
            return c < 3 ? 1e7 : 0;

        int &ans = dp[i][j][c];
        if (~ans)
            return ans;
        ans = solve(i + 1, j, min(c + 1, 3), s) + abs(j - (s[i] - 'a'));

        if (c == 3 || !i)
        {
            for (int cc = 0; cc < 26; cc++)
            {
                ans = min(ans, solve(i + 1, cc, (j == cc ? min(c + 1, 3) : 1), s) + abs(cc - (s[i] - 'a')));
            }
        }

        return ans;
    }

    void build(int i, int j, int c, string &s)
    {
        if (i == s.size())
            return;
        int ans = dp[i][j][c];

        if (c == 3 || !i)
        {
            for (int cc = 0; cc < 26; cc++)
            {
                if (ans == solve(i + 1, cc, (j == cc ? min(c + 1, 3) : 1), s) + abs(cc - (s[i] - 'a')))
                {
                    answer += char(cc + 'a');
                    build(i + 1, cc, (j == cc ? min(c + 1, 3) : 1), s);
                    return;
                }
            }
        }

        answer += char(j + 'a');
        build(i + 1, j, min(c + 1, 3), s);
    }

    string minCostGoodCaption(string &s)
    {
        if (s.size() < 3)
            return "";
        memset(dp, -1, sizeof dp);
        cout << solve(0, 27, 0, s) << '\n';
        build(0, 27, 0, s);
        return answer;
    }
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