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
const int N = 2e5 + 5;
struct node
{
    int prefix, sum;
};
int arrinput[N];
node arr[N * 4];

void merge(int i)
{
    arr[i].sum = arr[2 * i].sum + arr[2 * i + 1].sum;
    arr[i].prefix = max(arr[2 * i].prefix, arr[2 * i].sum + arr[2 * i + 1].prefix);
}

void builtsegmentTree(int i, int l, int r)
{
    if (l == r)
    {
        arr[i].prefix = arr[i].sum = arrinput[l];
        return;
    }
    int mid = l + (r - l) / 2;
    builtsegmentTree(2 * i, l, mid);
    builtsegmentTree(2 * i + 1, mid + 1, r);
    merge(i);
}

void update(int i, int l, int r, int &idx, int &val)
{
    if (idx < l || idx > r)
    {
        return;
    }
    if (l == r)
    {
        arrinput[idx] = val;
        arr[i].sum = arr[i].prefix = arrinput[l];
        return;
    }

    int mid = l + (r - l) / 2;
    update(i * 2, l, mid, idx, val);
    update(i * 2 + 1, mid + 1, r, idx, val);
    merge(i);
}

node getSum(int i, int l, int r, int &fl, int &fr)
{
    if (fr < l || fl > r)
    {
        return {0, 0};
    }
    if (l >= fl && r <= fr)
    {
        return arr[i];
    }
    node ans;
    int mid = l + (r - l) / 2;
    node left = getSum(i * 2, l, mid, fl, fr);
    node right = getSum(i * 2 + 1, mid + 1, r, fl, fr);
    ans.sum = left.sum + right.sum;
    ans.prefix = max(left.prefix, left.sum + right.prefix);
    return ans;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> arrinput[i];
        }
        builtsegmentTree(1, 0, n - 1);
        while (q--)
        {
            int a, b, c;
            cin >> c >> a >> b;
            if (c == 1)
            {
                a--;
                update(1, 0, n - 1, a, b);
            }
            else
            {
                a--;
                b--;
                node ans = getSum(1, 0, n - 1, a, b);
                a = max(ans.prefix, ans.sum);
                if (a < 0)
                {
                    a = 0;
                }
                cout << a << "\n";
            }
        }
    }

    return 0;
}