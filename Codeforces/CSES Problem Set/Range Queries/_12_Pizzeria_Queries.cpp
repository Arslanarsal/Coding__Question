#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet;
#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x;
template <class T>

int N = INT_MAX;
vector<int> arr(2e5 + 2);

struct segment
{
    vector<int> seg;
    segment(int n)
    {
        seg.resize(n * 4, 1e9);
    }
    void insert(int i, int l, int r, int idx, int val)
    {
        if (l > idx || r < idx)
        {
            return;
        }
        if (l == r)
        {
            seg[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        insert(i * 2, l, mid, idx, val);
        insert(i * 2 + 1, mid + 1, r, idx, val);
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }

    int getval(int i, int l, int r, int L, int R)
    {
        if (r < L || l > R)
        {
            return INT_MAX;
        }
        if (l >= L && r <= R)
        {
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        int left = getval(i * 2, l, mid, L, R);
        int right = getval(i * 2 + 1, mid + 1, r, L, R);
        return min(left, right);
    }
};

int32_t main()
{
    fastio;
    t = 1;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        segment up(n), down(n);
        for (int i = 1; i <= n; i++)
        {
            up.insert(1, 1, n, i, arr[i] + i);
            down.insert(1, 1, n, i, arr[i] - i);
        }
        while (q--)
        {
            int a, b, k;
            cin >> a;
            if (a == 1)
            {
                cin >> k >> b;
                arr[k] = b;
                up.insert(1, 1, n, k, arr[k] + k);
                down.insert(1, 1, n, k, arr[k] - k);
            }
            else
            {
                cin >> k;
                int left = down.getval(1, 1, n, 1, k) + k;
                int right = up.getval(1, 1, n, k, n) - k;
                cout << min(left, right) << "\n";
            }
        }
    }

    return 0;
}
