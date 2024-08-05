#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int arrx[4] = {-1, 0, 1, 0};
    int arry[4] = {0, 1, 0, -1};

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j)
    {
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int maxPath = 1;
        for (int k = 0; k < 4; ++k)
        {
            int newi = i + arrx[k];
            int newj = j + arry[k];
            if (newi >= 0 && newj >= 0 && newi < matrix.size() && newj < matrix[0].size() && matrix[newi][newj] > matrix[i][j])
            {
                maxPath = max(maxPath, 1 + dfs(matrix, memo, newi, newj));
            }
        }

        memo[i][j] = maxPath;
        return maxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}