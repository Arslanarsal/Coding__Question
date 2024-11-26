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

int bi(int n, int r)
{
    int res = 1;
    if (r > n - r)
    {
        r = n - r;
    }
    for (int i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int32_t main()
{
    fastio;

    cin >> t;

    while (t--)
    {
        int n, r, x, y;
        cin >> n >> r >> x >> y;

        int term = bi(n, r - 1) * pow(x, n - r + 1) * pow(y, r - 1);
        cout << term << endl;
    }

    return 0;
}