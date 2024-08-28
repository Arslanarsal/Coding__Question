#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
const int mod = 1e9 + 7;
int n;

class segmentTree
{
    vector<int> tree;

public:
    segmentTree(vector<int> &arr)
    {
        tree.resize(n * 4, 0);
        build(0, n - 1, 0);
    }

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            tree[i] = 1; 
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, i * 2 + 1);
        build(mid + 1, r, i * 2 + 2);
        tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
    }

    int getidx(int l, int r, int i, int num)
    {
        if (l == r)
        {
            tree[i]--; 
            return l; 
        }
        int mid = (l + r) / 2;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        int res;
        if (tree[left] > num)
        {
            res = getidx(l, mid, left, num);
        }
        else
        {
            res = getidx(mid + 1, r, right, num - tree[left]);
        }
        tree[i]--;
        return res;
    }
};

int32_t main()
{
    fastio;
    cin >> n;
    vector<int> arr(n), arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    segmentTree seg(arr);
    for (int i = 0; i < n; i++)
    {
        int idx = seg.getidx(0, n - 1, 0, arr1[i] - 1);
        cout << arr[idx] << " ";
    }

    return 0;
}
