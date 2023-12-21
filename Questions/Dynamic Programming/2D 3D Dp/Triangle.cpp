#include <bits/stdc++.h>
using namespace std;

/* 
    Time Complexity: O(2 ^ N)
    Space Complexity: O(2 ^ N)

    Where  N is the number of row in triangle array.
*/

int solve(int i, int j, vector<vector<int>> &triangle)
{
    // Base case
    if (i >= triangle.size() or j > i)
    {
        return 0;
    }

    // Recursive call.
    return min(solve(i + 1, j, triangle), solve(i + 1, j + 1, triangle)) + triangle[i][j];
}

int minimumPathSum(vector<vector<int>> triangle, int n)
{
    return solve(0, 0, triangle);
}



// int minimumTotal(vector<vector<int>> &triangle)
// {

//     int n = triangle.size();
//     for (int i = n-1; i >0 ; i--)
//     {
//         int m = triangle[i].size();
//         for (int j = 0; j < m-1; j++)
//         {
//             triangle[i-1][j] += min( triangle[i][j] ,  triangle[i][j+1]);
//         }
//     }
//     return triangle[0][0];
// }

int main()
{
    vector<vector<int>> v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(v);
    return 0;
}