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
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        vector<int> gap, block;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            gap.push_back(startTime[i] - end);
            end = endTime[i];
            block.push_back(endTime[i] - startTime[i]);
        }
        gap.push_back(eventTime - end);
        int m = gap.size();
        vector<int> pre(m), sir(m);
        pre[0] = gap[0];
        for (int i = 1; i < m; i++)
        {
            pre[i] = max(pre[i - 1], gap[i]);
        }
        sir[m - 1] = gap[m - 1];
        for (int i = m - 2; i >= 0; i--)
        {
            sir[i] = max(sir[i + 1], gap[i]);
        }
        int ans = 0;
        for (int i = 1; i < m; i++)
        {
            int temp = gap[i - 1] + gap[i];
            if ((i >= 2 && pre[i - 2] >= block[i - 1]) || (i < m - 1 && sir[i + 1] >= block[i - 1]))
            {
                temp += block[i - 1];
            }
            ans  = max(ans , temp);
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