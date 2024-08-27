#include <bits/stdc++.h>
using namespace std;
#define int long long int

class segmentTree
{
    vector<int> tree, lazytree;
    int n;

public:
    segmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(n * 4, 0);
        lazytree.resize(n * 4, 0);
        builtSegment(0, n - 1, 0, arr);
    }

    void builtSegment(int l, int r, int i, vector<int> &arr)
    {
        if (l == r)
        {
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        builtSegment(l, mid, i * 2 + 1, arr);
        builtSegment(mid + 1, r, i * 2 + 2, arr);
    }

    void update(int l, int r, int i, int &a, int &b, int &u)
    {
        if (r < a || l > b)
        {
            return;
        }
        if (l >= a && r <= b)
        {
            lazytree[i] += u;
            return;
        }
        int mid = l + (r - l) / 2;
        update(l, mid, i * 2 + 1, a, b, u);
        update(mid + 1, r, i * 2 + 2, a, b, u);
    }

    void getval(int l, int r, int i, int &idx, int &ans)
    {
        if (r < idx || l > idx)
        {
            return;
        }
        if (l == r)
        {
            tree[i] += lazytree[i];
            lazytree[i] = 0;
            ans = tree[i];
            return;
        }
        lazytree[i * 2 + 1] += lazytree[i];
        lazytree[i * 2 + 2] += lazytree[i];
        lazytree[i] = 0;
        int mid = l + (r - l) / 2;
        getval(l, mid, i * 2 + 1, idx, ans);
        getval(mid + 1, r, i * 2 + 2, idx, ans);
    }
    int getval(int idx)
    {
        int ans = 0;
        getval(0, n - 1, 0, idx, ans);
        return ans;
    }
};

int32_t main()
{
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
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            seg.update(0, n - 1, 0, a, b, u);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << seg.getval(idx - 1) << "\n";
        }
    }

    return 0;
}