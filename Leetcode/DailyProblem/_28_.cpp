#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2, int &n, int &m)
    {
        bool ans = true;
        queue<pair<int, int>> q;
        q.push({x, y});
        grid2[x][y] = false;
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (!grid1[i][j])
            {
                ans = false;
            }

            for (int k = 0; k < 4; k++)
            {
                int newi = i + row[k];
                int newj = j + col[k];
                if (newi >= 0 && newi < n && newj >= 0 && newj < m && grid2[newi][newj])
                {
                    grid2[newi][newj] = false;
                    q.push({newi, newj});
                }
            }
        }
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int ans = 0;
        int n = grid1.size();
        int m = grid1[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j])
                {
                    ans += solve(i, j, grid1, grid2, n, m);
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