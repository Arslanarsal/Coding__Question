#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Node;
int arrx[4] = {-1, 0, 1, 0};
int arry[4] = {0, 1, 0, -1};
char side[4] = {'U', 'R', 'D', 'L'};

string findShortestPath(vector<string> &grid, int startX, int startY)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<char>> direction(n, vector<char>(m));
    queue<Node> q;
    q.push({0, {startX, startY}});
    visited[startX][startY] = 1;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();
        int dist = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        if (grid[x][y] == 'B')
        {
            string path = "";
            while (grid[x][y] != 'A')
            {
                char dir = direction[x][y];
                path += dir;
                if (dir == 'U')
                    x++;
                else if (dir == 'D')
                    x--;
                else if (dir == 'L')
                    y++;
                else if (dir == 'R')
                    y--;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + arrx[i];
            int newY = y + arry[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && (grid[newX][newY] == '.' || grid[newX][newY] == 'B'))
            {
                visited[newX][newY] = 1;
                direction[newX][newY] = side[i];
                q.push({dist + 1, {newX, newY}});
            }
        }
    }

    return "";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int startX, startY;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    string result = findShortestPath(grid, startX, startY);
    if (!result.empty())
    {
        cout << "YES\n";
        cout << result.size() << "\n";
        cout << result << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
