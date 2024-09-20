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
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, m, q, x;
int ans = 1;

void update(int u, int v, int val, vector<int> &pos, vector<pair<int, int>> &arr)
{
    int i = pos[u];
    int j = pos[v];
    if (i > j)
    {
        swap(i, j);
    }

    if (i > 0 && arr[i - 1] > arr[i])
    {
        ans += val;
    }

    if (j > n - 1 && arr[j] > arr[j + 1])
    {
        ans += val;
    }

    if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            ans += val;
        }
    }
    else
    {
        if (arr[i] > arr[i + 1])
        {
            ans += val;
        }

        if (arr[j - 1] > arr[j])
        {
            ans += val;
        }
    }
}

int32_t main()
{
    fastio;
    t = 1;
    while (t--)
    {
        cin >> n >> m;
        vector<pair<int, int>> arr(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
            pos[i] = arr[i].first;
        }
        sort(arr.begin(), arr.end());

        int pre = arr[1].second;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i].second < pre)
            {
                ans++;
            }
        }
        cout << ans << "\n";
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            update(a, b, -1, pos, arr);
            int i = pos[a], j = pos[b];
            swap(pos[a], pos[b]);
            swap(arr[i].second, arr[j].second);
            update(a, b, 1, pos, arr);
            cout << ans << "\n";
        }
    }

    return 0;
}
