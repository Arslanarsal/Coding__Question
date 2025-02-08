#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
const int N = 8;
vector<vector<int>> grid(N, vector<int>(N, -1));

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int countOnwardMoves(int x, int y)
{
    int count = 0;
    for (int k = 0; k < 8; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && grid[nx][ny] == -1)
        {
            count++;
        }
    }
    return count;
}

bool solve(int i, int j, int count)
{
    if (count == N * N + 1)
    {
        return true;
    }

    vector<pair<int, pair<int, int>>> moves;
    for (int k = 0; k < 8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && y >= 0 && x < N && y < N && grid[x][y] == -1)
        {
            int onwardMoves = countOnwardMoves(x, y);
            moves.push_back({onwardMoves, {x, y}});
        }
    }

    sort(moves.begin(), moves.end());

    for (pair<int, pair<int, int>> nextMove : moves)
    {
        int x = nextMove.second.first;
        int y = nextMove.second.second;

        grid[x][y] = count;
        if (solve(x, y, count + 1))
            return true;

        grid[x][y] = -1;
    }

    return false;
}

int32_t main()
{
    fastio;
    int n, m;
    cin >> m >> n;

    n--;
    m--;

    grid[n][m] = 1;
    if (!solve(n, m, 2))
    {
        cout << "No solution found.\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
