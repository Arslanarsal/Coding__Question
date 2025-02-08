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
    void solve(string temp, int i, int &num, vector<string> &ans)
    {
        if (i == num)
        {
            ans.push_back(temp);
            return;
        }
        solve(temp + "0", i + 1, num, ans);
        if (temp[i - 1] == '0')
        {
            solve(temp + "1", i + 1, num, ans);
        }
        return;
    }

public:
    vector<string> generateBinaryStrings(int num)
    {
        vector<string> ans;
        solve("0", 1, num, ans);
        solve("1", 1, num, ans);
        return ans;
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