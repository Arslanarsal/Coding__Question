#include <bits/stdc++.h>
using namespace std;

vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        int y = i;
        while (x < n && y >= 0)
        {
            ans.push_back(matrix[x][y]);
            x++;
            y--;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int x = i;
        int y = m-1;
        while (x < n && y >= 0)
        {
            ans.push_back(matrix[x][y]);
            x++;
            y--;
        }
    }
    return ans;
}

int main()
{

    return 0;
}