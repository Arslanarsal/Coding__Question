#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();

    if (image[sr][sc] == color) {
        return image;
    }

    int originalColor = image[sr][sc]; // Store original color
    queue<pair<int, int>> qu;
    qu.push({sr, sc});

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != originalColor) {
            continue;
        }

        image[x][y] = color; // Update color

        // Push adjacent cells to the queue
        qu.push({x + 1, y});
        qu.push({x - 1, y});
        qu.push({x, y + 1});
        qu.push({x, y - 1});
    }
    return image;
}

// vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
// {
//     if (image[sr][sc] == color)
//     {
//         return image;
//     }
//     int n = image.size();
//     int m = image[0].size();
//     queue<pair<int, int>> qu;
//     qu.push({sr, sc});
//     while (!qu.empty())
//     {
//         sr = qu.front().first;
//         sc = qu.front().second;
//         qu.pop();

//         if (sr + 1 < n && image[sr][sc] == image[sr + 1][sc])
//         {
//             qu.push({sr + 1, sc});
//         }
//         if (sr - 1 >= 0 && image[sr][sc] == image[sr - 1][sc])
//         {
        
//             qu.push({sr - 1, sc});
//         }

//         if (sc + 1 < m && image[sr][sc] == image[sr][sc + 1])
//         {
//             qu.push({sr, sc + 1});
//         }
//         if (sc - 1 >=0 && image[sr][sc] == image[sr][sc - 1])
//         {
//             qu.push({sr, sc - 1});
//         }
//         image[sr][sc] = color;
//     }
//     return image;
// }

int main()
{
    vector<vector<int>> adj = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},

    };
    vector<vector<int>> ans = floodFill(adj, 1, 1, 2);
    for (auto x : ans)
    {
        for (auto &&i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}