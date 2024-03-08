#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, row0 = 1;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i != 0)
                    {
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        row0 = 0;
                    }

                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][0] = 0;
            }
            for (int i = 0; i < col; i++)
            {
                matrix[0][i] = 0;
            }
        }
        else
        {
            if (row0 == 0)
            {
                for (int i = 0; i < col; i++)
                {
                    matrix[0][i] = 0;
                }
            }

            if (col0 == 0)
            {
                for (int i = 0; i < row; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix;
    matrix = {{1, 0}};

    sol.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}