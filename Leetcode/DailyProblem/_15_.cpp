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
public:
    bool checkInclusion(string s1, string s2)
    {
        int arr[26] = {0};
        int n = s1.size(), m = s2.size();
        for (int i = 0; i < n; i++)
        {
            arr[s1[i] - 'a']++;
        }
        int temp[26];
        copy(arr, arr + 26, temp);
        int count = 0;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            int num = s2[i] - 'a';
            if (temp[num])
            {
                temp[num]--;
                count++;
            }
            else
            {
                while ((s2[j] - 'a') != num)
                {
                    j++;
                    temp[s2[j] - 'a']++;
                    count--;
                }
                j++;
                if (temp[s2[j] - 'a'] < arr[s2[j] - 'a'])
                {
                    count--;
                    temp[s2[j] - 'a']++;
                }
            }

            if (count == n)
            {
                return true;
            }
        }
        return false;
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
