#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;

        int row = 0;
        while (i < n)
        {
            int j = 0;
            while (j < (m / 2))
            {
                if (grid[i][j] != grid[i][m - j - 1])
                {
                    row++;
                }
                j++;
            }
            i++;
        }

        int col = 0;
        i = 0;
        while (i < m)
        {
            int j = 0;
            while (j < (n / 2))
            {
                if (grid[j][i] != grid[n - j - 1][i])
                {
                    col++;
                }
                j++;
            }
            i++;
        }
        int ans = min(row, col);
        return ans;
    }
};

int main()
{

    return 0;
}