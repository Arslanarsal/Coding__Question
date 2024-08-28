#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
vector<string> arr;
vector<vector<int>> grid;
int n, q;

int32_t main()
{
    fastio;
    cin >> n >> q;
    arr.resize(n);
    grid.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            grid[i][j] = grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
            if (arr[i - 1][j - 1] == '*')
            {
                grid[i][j]++;
            }
        }
    }
    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = grid[x2][y2] - grid[x2][y1 - 1] - grid[x1 - 1][y2] + grid[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }

    return 0;
}