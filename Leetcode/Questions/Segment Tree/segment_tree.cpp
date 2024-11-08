#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll N, n;
vl segment(N * 4);
vl arr(n);

void segmentTree(int i, int l, int r)
{
    if (l == r)
    {
        segment[i] = arr[r];
        return;
    }
    ll mid = (l + r) / 2;
    segmentTree(2 * i + 1, l, mid);
    segmentTree(2 * i + 2, mid + 1, r);
    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    return;
}

void segmentTreeUpdate(int ind, int val, int i, int l, int r)
{
    if (l == r)
    {
        segment[i] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (ind <= mid)
        segmentTreeUpdate(ind, val, 2 * i + 1, l, mid);
    else
        segmentTreeUpdate(ind, val, 2 * i + 2, mid + 1, r);

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    return;
}

int main()
{
    n = 0;
    N = n;

    return 0;
}