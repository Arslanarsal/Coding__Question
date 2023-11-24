#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int flag = true;
    queue<pair<int, int>> qu;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                qu.push({i, j});
            }
            if (grid[i][j] == 1)
            {
                flag = false;
            }
        }
    }
    if (qu.empty() && flag)
    {
        return 0;
    }
    if (qu.empty() && flag==false)
    {
        return -1;
    }
    qu.push({-1, -1});
    int ans = 0;
    while (!qu.empty())
    {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        if (x == -1 && y == -1)
        {
            if (!qu.empty())
            {
                ans++;
                qu.push({-1, -1});
                continue;
            }
            break;
        }
        if (x + 1 < n && grid[x + 1][y] == 1)
        {
            qu.push({x + 1, y});
            grid[x + 1][y] = 2;
        }
        if (x - 1 >= 0 && grid[x - 1][y] == 1)
        {
            qu.push({x - 1, y});
            grid[x - 1][y] = 2;
        }
        if (y + 1 < n && grid[x][y + 1] == 1)
        {
            qu.push({x, y + 1});
            grid[x][y + 1] = 2;
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1)
        {
            qu.push({x, y - 1});
            grid[x][y - 1] = 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return ans;
}
int main()
{
    // vector<vector<int>> v = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> v = {{1}};
    cout << orangesRotting(v) << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}