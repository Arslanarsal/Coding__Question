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
    int sumOfGoodNumbers(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i - k >= 0 && nums[i] > nums[i - k] || (i + k < n && nums[i] > nums[i + k]))
            {
                ans += nums[i];
            }
        }
        return ans;
    }
};

int32_t
main()
{
    Solution aol;
    vector<int> nums = {2, 1};
    int k = 2;
    cout << aol.sumOfGoodNumbers(nums, k) << endl;
    return 0;
}