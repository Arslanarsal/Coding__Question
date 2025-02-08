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
string s;
int kmp[101]{};
int dp[1001][101]{};

void solve_kmp()
{
    kmp[0] = 0;

    for (int i = 1; i < m; i++)
    {
        int j = kmp[i - 1];
        while (true)
        {
            if (s[i] == s[j])
            {
                kmp[i] = j + 1;
                break;
            }
            else if (j)
            {
                j = kmp[j - 1];
            }
            else
            {
                kmp[i] = 0;
                break;
            }
        }
    }
    return;
}

int solve_Required(int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (i >= n)
    {
        return dp[i][j] = (j >= m) ? 1 : 0;
    }
    if (j >= m)
    {
        return dp[i][j] = ((26 * solve_Required(i + 1, j)) % mod);
    }
    int ans = 0;
    int t;
    for (int k = 0; k < 26; k++)
    {
        t = j;
        while (true)
        {
            if ((s[t] - 'A') == k)
            {
                t++;
                break;
            }
            else if (t)
            {
                t = kmp[t - 1];
            }
            else
            {
                break;
            }
        }
        ans = (ans + solve_Required(i + 1, t)) % mod;
    }
    return dp[i][j] = ans;
}

int32_t main()
{
    fastio;

    cin >> n;
    cin >> s;
    m = s.size();
    memset(dp, -1, sizeof(dp));
    memset(kmp, 0, sizeof(kmp));
    solve_kmp();

    cout << solve_Required(0, 0) << "\n";

    return 0;
}