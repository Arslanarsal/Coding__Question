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

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        priority_queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int row = i;
            int col = 0;
            while (row < n && col < n)
            {
                q.push(grid[row][col]);
                row++;
                col++;
            }
            row = i;
            col = 0;
            while (!q.empty())
            {
                grid[row][col] = q.top();
                q.pop();
                row++;
                col++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < n; i++)
        {
            int row = 0;
            int col = i;
            while (row < n && col < n)
            {
                pq.push(grid[row][col]);
                row++;
                col++;
            }
            row = 0;
            col = i;
            while (!pq.empty())
            {
                grid[row][col] = pq.top();
                pq.pop();
                row++;
                col++;
            }
        }

        return grid;
    }
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
    }

    return 0;
}