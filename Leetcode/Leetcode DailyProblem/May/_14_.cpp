#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j] || grid[i][j] == -1)
        {
            return 0;
        }

        int num = grid[i][j];
        grid[i][j] = -1;

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};
        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            ans = max(ans, solve(grid, i + x[k], j + y[k]));
        }
        grid[i][j] = num;
        return ans + grid[i][j];
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    ans = max(ans, solve(grid, i, j));
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}