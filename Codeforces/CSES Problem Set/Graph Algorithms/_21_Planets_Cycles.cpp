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
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q;

int nextNode[200006];
int ans[200005];

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nextNode[i];
    }
    memset(ans, -1, sizeof(ans));

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            unordered_set<int> done;
            vector<int> tempVec;

            int x = i;
            while (done.find(x) == done.end())
            {
                if (ans[x] != -1)
                {
                    break;
                }
                tempVec.push_back(x);
                done.insert(x);
                x = nextNode[x];
            }
            int m = tempVec.size();
            if (ans[x] != -1)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    ans[tempVec[j]] = ans[nextNode[tempVec[j]]] + 1;
                }
            }
            else
            {
                int idx = find(tempVec.begin(), tempVec.end(), x) - tempVec.begin();
                int h = m - idx;
                for (int j = idx; j < m; j++)
                {
                    ans[tempVec[j]] = h;
                }
                for (int j = idx - 1; j >= 0; j--)
                {
                    ans[tempVec[j]] = ans[nextNode[tempVec[j]]] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}