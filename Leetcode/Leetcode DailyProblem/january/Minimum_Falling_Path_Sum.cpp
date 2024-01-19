#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = n - 2;
        while (i >= 0)
        {
            int j = 0;
            while (j < m)
            {
                int left = INT_MAX, right = INT_MAX, down;
                if (j > 0)
                {
                    left = matrix[i + 1][j - 1];
                }
                down = matrix[i + 1][j];
                if (j < m - 1)
                {
                    right = matrix[i + 1][j + 1];
                }

                matrix[i][j] += min({left, right, down});
                j++;
            }
            i--;
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] < ans)
            {
                ans = matrix[0][i];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}