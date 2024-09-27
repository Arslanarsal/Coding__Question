#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define pii pair<int, int>

int t, n, q, m, x;

struct range
{
    int left, right, index;
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        vector<range> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].left;
            cin >> arr[i].right;
            arr[i].index = i;
        }
        vector<int> ans(n, 0);
        int room = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        sort(arr.begin(), arr.end(), [&](range a, range b)
             { return a.left < b.left; });
        for (int i = 0; i < n; i++)
        {
            if (pq.empty() || pq.top().first >= arr[i].left)
            {
                ans[arr[i].index] = ++room;
                pq.push({arr[i].right, room});
            }
            else
            {
                ans[arr[i].index] = pq.top().second;
                pq.pop();
                pq.push({arr[i].right, ans[arr[i].index]});
            }
        }
        cout << room << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}