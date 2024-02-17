#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ele(m, -1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ele[i] = max(ele[i], matrix[j][i]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[j][i] == -1)
                {
                    matrix[j][i] = ele[i];
                }
            }
        }
        return matrix;
    }
};

int main()
{
    Solution so;
    vector<vector<int>> mat = {{1, 2, -1}, {4, -1, 6}, {7, 8, 9}};
    so.modifiedMatrix(mat);

    return 0;
}