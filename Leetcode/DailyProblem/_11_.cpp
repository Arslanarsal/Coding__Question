#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int idx, int jdx, vector<vector<int>> &grid, vector<vector<bool>> &vist, int &n, int &m)
    {
        int arrx[4] = {-1, 0, 1, 0};
        int arry[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({idx, jdx});
        vist[idx][jdx] = true;
        while (!q.empty())
        {
            int id = q.front().first;
            int jd = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newi = id + arrx[i];
                int newj = jd + arry[i];
                if (newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] && !vist[newi][newj])
                {
                    q.push({newi, newj});
                    vist[newi][newj] = true;
                }
            }
        }
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        int idx, idj;
        vector<vector<bool>> vist1(n, vector<bool>(m, 0));
        vector<vector<bool>> vist2(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !vist1[i][j])
                {
                    solve(i, j, grid, vist1, n, m);
                    idx = i, idj = j;
                    island++;
                }
            }
        }
        if (island != 1)
        {
            return 0;
        }
        int arrx[4] = {-1, 0, 1, 0};
        int arry[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({idx, idj});
        vist2[idx][idj] = true;
        while (!q.empty())
        {
            int id = q.front().first;
            int jd = q.front().second;
            q.pop();
            vector<vector<bool>> vist3(n, vector<bool>(m, 0));
            vist3[id][jd] = true;
            island = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] && !vist3[i][j])
                    {
                        solve(i, j, grid, vist3, n, m);
                        idx = i, idj = j;
                        island++;
                    }
                }
            }
            if (island != 1)
            {
                return 1;
            }

            for (int i = 0; i < 4; i++)
            {
                int newi = id + arrx[i];
                int newj = jd + arry[i];
                if (newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] && !vist2[newi][newj])
                {
                    q.push({newi, newj});
                    vist2[newi][newj] = true;
                }
            }
        }
        return 2;
    }
};

int main()
{
    Solution sol;

    return 0;
}