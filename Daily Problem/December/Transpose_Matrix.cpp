#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
/*
    Time complexity: O(M*N)
    Space complexity: O(M*N)

    Where 'M' and 'N' are the size of the matrix.
*/

vector<vector<int>> transpose(vector<vector<int>> &matric)
{

    // New matrix to store transpose.
    int n = matric.size();
    int m = matric[0].size();
    vector<vector<int>> transMat(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            // Assign values.
            transMat[i][j] = matric[j][i];
        }
    }

    return transMat;
}