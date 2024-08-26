#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define ld long double
const int mod = 1e9 + 7;

int n, q;

class SegmentTree
{
    vector<int> segmentTre;

public:
    SegmentTree(vector<int> &arr)
    {
        segmentTre.resize(4 * n);
        buildSegmentTree(arr, 0, 0, n - 1);
    }

    void buildSegmentTree(vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            segmentTre[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(arr, 2 * i + 1, l, mid);
        buildSegmentTree(arr, 2 * i + 2, mid + 1, r);
        segmentTre[i] = (segmentTre[2 * i + 1] ^ segmentTre[2 * i + 2]);
    }

    int XOR(int s, int e, int l, int r, int i)
    {
        if (e < l || s > r)
        {
            return 0;
        }
        if (l >= s && r <= e)
        {
            return segmentTre[i];
        }
        int mid = l + (r - l) / 2;
        int leftSum = XOR(s, e, l, mid, 2 * i + 1);
        int rightSum = XOR(s, e, mid + 1, r, 2 * i + 2);
        return (leftSum ^ rightSum);
    }

    int XOR(int s, int e)
    {
        return XOR(s, e, 0, n - 1, 0);
    }
};

int32_t main()
{
    fastio;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree seg(arr);
    while (q--)
    {
        int s, r;
        cin >> s >> r;
        cout << seg.XOR(s - 1, r - 1) << '\n';
    }

    return 0;
}
