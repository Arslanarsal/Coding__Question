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


class Solution
{
    int N;
    void solve(int num, vector<int> &ans)
    {
        ans.push_back(num);
        for (int i = 0; i < 10; i++)
        {
            int temp = num;
            temp = temp * 10 + i;
            if (temp <= N)
            {
                solve(temp, ans);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n)
    {
        N = n;
        vector<int> ans;
        for (int i = 1; i < 10; i++)
        {
            if (i <= N)
            {
               solve(i, ans);
            }
            
        }

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
