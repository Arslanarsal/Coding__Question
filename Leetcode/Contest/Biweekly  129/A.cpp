#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(vector<vector<char>> &grid, int i, int j, int m)
    {
        int ans = 0;
        if (j < m - 1)
        {
            if (grid[i][j + 1] != grid[i][j])
            {
                ans++;
            }
            if (grid[i + 1][j] != grid[i][j])
            {
                ans++;
            }
            if (grid[i + 1][j + 1] != grid[i][j])
            {
                ans++;
            }
            if (ans < 2)
            {
                return true;
            }
        }
        //

        if (j > 0)
        {
            ans = 0;
            if (grid[i][j - 1] != grid[i][j])
            {
                ans++;
            }
            if (grid[i + 1][j] != grid[i][j])
            {
                ans++;
            }
            if (grid[i + 1][j - 1] != grid[i][j])
            {
                ans++;
            }
        }
        // cout << ans << endl;
        return ans < 2;
    }

public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check(grid, i, j, m))
                {
                    cout << i << " " << j << endl;
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> ch = {{'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
    Solution sol;
    cout << sol.canMakeSquare(ch);
    return 0;
}