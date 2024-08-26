#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;

class segmentTree
{
    vector<int> tree;

public:
    segmentTree(vector<int> &arr)
    {
        int n = arr.size();
        tree.resize(4 * n, INT_MAX);
        builtTree(arr, 0, n - 1, 0);
    }
    void builtTree(vector<int> &arr, int l, int r, int i)
    {
        if (l == r)
        {
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        builtTree(arr, l, mid, i * 2 + 1);
        builtTree(arr, mid + 1, r, i * 2 + 2);
        tree[i] = min(tree[i * 2 + 1], tree[i * 2 + 2]);
    }

    void update(int l, int r, int i, int &idx, int &val, int &pre)
    {
        if (r < idx || l > idx)
        {
            return;
        }
        if (l == r)
        {
            tree[i] = val;
            return;
        }
        if (tree[i] == pre)
        {
            tree[i] = INT_MAX;
        }
        int mid = l + (r - l) / 2;
        update(l, mid, i * 2 + 1, idx, val, pre);
        update(mid + 1, r, i * 2 + 2, idx, val, pre);
        tree[i] = min(tree[i * 2 + 1], tree[i * 2 + 2]);
    }

    int getmax(int l, int r, int &s, int &e, int i)
    {
        if (r < s || l > e)
        {
            return INT_MAX;
        }
        if (l >= s && r <= e)
        {
            return tree[i];
        }
        int mid = l + (r - l) / 2;
        int ans = getmax(l, mid, s, e, i * 2 + 1);
        ans = min(ans, getmax(mid + 1, r, s, e, i * 2 + 2));
        return ans;
    }
};

int32_t main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segmentTree seg(arr);
    while (q--)
    {
        int t, s, e;
        cin >> t >> s >> e;
        s--;
        if (t == 1)
        {

            int temp = arr[s];
            arr[s] = e;
            seg.update(0, n - 1, 0, s, e, temp);
        }
        else
        {
            e--;
            int temp = arr[s];
            arr[s] = e;
            cout << seg.getmax(0, n - 1, s, e, 0) << "\n";
        }
    }

    return 0;
}