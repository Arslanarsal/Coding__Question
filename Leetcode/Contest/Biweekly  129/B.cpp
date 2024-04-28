#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n + 1, 0);
        vector<int> col(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    res = res + ((row[i] - 1) * (col[j] - 1));
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}