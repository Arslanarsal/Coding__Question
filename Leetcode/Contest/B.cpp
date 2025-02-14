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
    int solve(int i, int mask, vector<int> &nums, vector<int> &blcm, int &m, int &n)
    {
        if (mask == (1<< m) )
        {
          return 0;
        }
        if (i >= n)
        {
           return 1e9;
        }
        
        
        int ans = 1e9;
        ans = min(ans, solve(i + 1, mask, nums, blcm, m, n));

        for (int subset = 0; subset < (1 << m); subset++)
        {
            int subsetLcm = blcm[subset];
            int temp = (nums[i] / subsetLcm) * subsetLcm;
            ans = min(ans, solve(i + 1, mask | subset, nums, blcm, m, n) + (temp - nums[i]));
        }
    }

    int findGcd(int a, int b)
    {
        return ((a * b) / __gcd(a, b));
    }

    void lcmm(vector<int> &target, vector<int> &blcm, int &m)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            blcm[mask] = 1;
            for (int i = 0; i < (1 << m); i++)
            {
                if (mask & (1 << i))
                {
                    blcm[mask] = findGcd(blcm[mask], target[i]);
                }
            }
        }
    }

public:
    int minimumIncrements(vector<int> &nums, vector<int> &target)
    {

        int n = nums.size();
        int m = target.size();
        vector<int> blcm(m);
        lcmm(target, blcm, m);
        return solve(0, 0, nums, blcm, m, n);
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