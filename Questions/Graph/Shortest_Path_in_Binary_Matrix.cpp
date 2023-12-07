#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }

    /*
    Time complexity: O(M * N)
    Space complexity: O(M * N)

    Where M is number of rows and N is number of columns in the matrix
*/

    // Function to find the shortest path between a given source cell to a destination cell
    int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // Check source cell of the matrix have value 1
        if (!matrix[src.first][src.second])
        {
            return -1;
        }

        int ans = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        // Mark the source cell as visited
        visited[src.first][src.second] = 1;

        // Create a queue for BFS
        queue<pair<int, int>> q;
        q.push(src);

        // Array details of all 4 possible movements from a cell
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        // Do a BFS starting from source cell
        while (q.size())
        {
            int sz = q.size();

            // Traverse the current level
            for (int i = 0; i < sz; i++)
            {
                pair<int, int> node = q.front();
                q.pop();

                // If we have reached the destination cell, return current distance
                if (node.first == dest.first && node.second == dest.second)
                {
                    return ans;
                }

                for (int j = 0; j < 4; j++)
                {
                    int newX = dx[j] + node.first;
                    int newY = dy[j] + node.second;

                    // If adjacent cell is valid, has path and not visited yet, enqueue it
                    if (newX >= 0 && newY >= 0 && newX < n && newY < m && !visited[newX][newY] && matrix[newX][newY])
                    {
                        visited[newX][newY] = 1;
                        q.emplace(newX, newY);
                    }
                }
            }
            // Increment distance by 1, as destination cell is not present in current level
            ans++;
        }
        // Return -1, if destination cannot be reached
        return -1;
    }
};

// for 8th direction

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1; // Check if start/end points are blocked

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    grid[0][0] = 1; // Marking as visited

    int steps = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto it = q.front();
            int r = r = it.first;
            int c = it.second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return steps; // Reached the destination

            for (const auto &dir : dirs)
            {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0)
                {
                    q.push({nr, nc});
                    grid[nr][nc] = 1; // Mark as visited
                }
            }
        }
        steps++; // Increment steps for each level of BFS traversal
    }

    return -1; // No path found
}

int main()
{
    // Driver Code.

    // pair<int, int> source, destination;
    // source.first = 0;
    // source.second = 1;
    // destination.first = 2;
    // destination.second = 2;

    // vector<vector<int>> grid = {{1, 1, 1, 1},
    //                             {1, 1, 0, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 0, 0},
    //                             {1, 0, 0, 1}};

    // Solution obj;

    // int res = obj.shortestPath(grid, source, destination);

    // cout << res;
    // cout << endl;

    vector<vector<int>> grid = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0},

    };

    int res = shortestPathBinaryMatrix(grid);

    cout << res;
    cout << endl;

    return 0;
}