#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;

vector<vector<int>> arr;

void update(int x, int y, int val)
{
    for (int i = x; i <= n; i += ((-i) & i))
    {
        for (int j = y; j <= n; j += ((-j) & j))
        {
            arr[i][j] += val;
        }
    }
}

int get_sum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= ((-i) & i))
    {
        for (int j = y; j > 0; j -= ((-j) & j))
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int32_t main()
{
    fastio;

    cin >> n >> q;
    arr.resize(n + 1, vector<int>(n + 1, 0));
    vector<string> arrste(n);
    for (int i = 0; i < n; i++)
    {

        cin >> arrste[i];
        for (int j = 0; j < n; j++)
        {
            if (arrste[i][j] == '*')
            {
                update(i + 1, j + 1, 1);
            }
        }
    }

    while (q--)
    {
        cin >> m;
        int x1, x2, y1, y2;
        if (m == 1)
        {
            cin >> x1 >> y1;

            if (arrste[x1 - 1][y1 - 1] == '*')
            {
                arrste[x1 - 1][y1 - 1] = '.';
                update(x1, y1, -1);
            }
            else
            {
                arrste[x1 - 1][y1 - 1] = '*';
                update(x1, y1, 1);
            }
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = get_sum(x2, y2) - get_sum(x1 - 1, y2) - get_sum(x2, y1 - 1) + get_sum(x1 - 1, y1 - 1);
            cout << ans << "\n";
        }
    }

    return 0;
}