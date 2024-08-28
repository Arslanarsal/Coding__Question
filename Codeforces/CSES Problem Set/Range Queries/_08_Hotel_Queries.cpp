#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int n, m;

class segmentTree
{
    vector<int> tree;

public:
    segmentTree(vector<int> &arr)
    {
        tree.resize(n * 4, 0);
        built(0, n - 1, 0, arr);
    }

    void built(int l, int r, int i, vector<int> &arr)
    {
        if (l == r)
        {
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        built(l, mid, i * 2 + 1, arr);
        built(mid + 1, r, i * 2 + 2, arr);
        tree[i] = max(tree[i * 2 + 1], tree[i * 2 + 2]);
    }
    int getidx(int l, int r, int i, int &num)
    {
        if (l == r && tree[i] < num)
        {
            return -1;
        }
        if (l == r)
        {
            tree[i] -= num;
            return l;
        }
        int mid = l + (r - l) / 2;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (tree[left] >= num)
        {
            int ret = getidx(l, mid, left, num);
            tree[i] = max(tree[left], tree[right]);
            return ret;
        }
        else if (tree[right] >= num)
        {
            int ret = getidx(mid + 1, r, right, num);
            tree[i] = max(tree[left], tree[right]);
            return ret;
        }
        return -1;
    }
};

int32_t main()
{
    fastio;
    cin >> n >> m;
    vector<int> arr(n), arr1(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    segmentTree seg(arr);
    for (int i = 0; i < m; i++)
    {
        int ans = seg.getidx(0, n - 1, 0, arr1[i]);
        cout << ans + 1 << " ";
    }

    return 0;
}