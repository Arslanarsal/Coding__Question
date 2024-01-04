#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int num = q.front().second;
        q.pop();
        ans[row][col] = num;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0)
            {
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, num + 1});
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), INF = m + n, v1, v2;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (mat[r][c] == 0)
                    continue;
                v1 = v2 = INF;
                if (r > 0)
                    v1 = mat[r - 1][c];
                if (c > 0)
                    v2 = mat[r][c - 1];
                mat[r][c] = min(v1, v2) + 1;
            }
        }

        for (int r = m - 1; r >= 0; r--)
        {
            for (int c = n - 1; c >= 0; c--)
            {
                if (mat[r][c] == 0)
                    continue;
                v1 = v2 = INF;
                if (r < m - 1)
                    v1 = mat[r + 1][c];
                if (c < n - 1)
                    v2 = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(v1, v2) + 1);
            }
        }

        return mat;
    }
};