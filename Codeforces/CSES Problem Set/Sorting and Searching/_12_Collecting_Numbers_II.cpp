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
int ans = 1;
vector<pair<int, int>> arr;
vector<int> pos;

void update(int a, int b, int val)
{
    // cout << a << " " << b << "\n";
    int i = pos[a], j = pos[b];
    if (i > j)
    {
        swap(i, j);
    }
    // cout << i << " " << j << "\n";
    if (i > 1 && arr[i - 1].second > arr[i].second)
    {
        ans += val;
    }
    if (j < n && arr[j + 1].second < arr[j].second)
    {
        ans += val;
    }

    if (i + 1 == j)
    {
        if (arr[i].second > arr[j].second)
        {
            ans += val;
        }
    }
    else
    {
        if (arr[i + 1].second < arr[i].second)
        {
            ans += val;
        }
        if (arr[j - 1].second > arr[j].second)
        {
            ans += val;
        }
    }
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        arr.resize(n + 1);
        pos.resize(n + 1);
        arr[0].first = -1;
        arr[0].second = -1;
        pos[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
            pos[i] = arr[i].first;
        }
        sort(arr.begin(), arr.end());
        for (int i = 2; i <= n; i++)
        {
            if (arr[i - 1].second > arr[i].second)
            {
                ans++;
            }
        }
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            int i = pos[a], j = pos[b];
            update(a, b, -1);
            // cout << ans << "\n";
            swap(pos[a], pos[b]);
            swap(arr[i].second, arr[j].second);
            update(a, b, 1);
            cout << ans << "\n";
        }
    }

    return 0;
}
