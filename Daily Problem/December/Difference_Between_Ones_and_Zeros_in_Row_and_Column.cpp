#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();

//     vector<pair<int, int>> row(n);
//     vector<pair<int, int>> col(m);

//     for (int i = 0; i < n; i++)
//     {
//         int zero = 0;
//         int ones = 0;
//         int zeroc = 0;
//         int onesc = 0;
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j])
//             {

//                 ones++;
//             }
//             else
//             {
//                 zero++;
//             }
//             if (grid[j][i])
//             {
//                 onesc++;
//             }
//             else
//             {
//                 zeroc++;
//             }
//         }
//         row[i] = {ones, zero};
//         col[i] = {onesc, zeroc};
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int ones = row[i].first;
//             int zero = row[i].second;

//             int onesc = col[j].first;
//             int zeroc = col[j].second;
//             grid[i][j] = ones + onesc - zero - zeroc;
//         }
//     }

//     return grid;
// }

vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> rowOnes(m, 0);
    vector<int> colOnes(n, 0);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rowOnes[i] += grid[i][j];
            colOnes[j] += grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << rowOnes[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << colOnes[i] << "  ";
    }
    cout << endl;
    // Calculate the difference matrix
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = 2 * (rowOnes[i] + colOnes[j]) - m - n;
        }
        cout << endl;
    }

    return grid;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    v = onesMinusZeros(v);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
   

    return 0;
}
