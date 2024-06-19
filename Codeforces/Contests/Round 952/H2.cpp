#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, -1, 0, 1}; // Direction vectors for DFS
const int dy[4] = {1, 0, -1, 0};
int n, m;
int rowDots[1000004], colDots[1000004];
string grid[1000004];
vector<vector<int>> visited, prefixSum;
int upperBound, lowerBound, leftBound, rightBound, componentSize;

void dfs(int x, int y)
{
    lowerBound = max(lowerBound, x);
    leftBound = min(leftBound, y);
    rightBound = max(rightBound, y);
    componentSize++;
    visited[x][y] = 1;

    for (int direction = 0; direction < 4; direction++)
    {
        int newX = x + dx[direction], newY = y + dy[direction];
        if (newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == '#' && !visited[newX][newY])
            dfs(newX, newY);
    }
}

void solve()
{
    cin >> n >> m;
    memset(rowDots, 0, n * sizeof(int));
    memset(colDots, 0, m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
                rowDots[i]++, colDots[j]++;
    }

    visited.clear(), prefixSum.clear();
    visited.resize(n, vector<int>(m, 0));
    prefixSum.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#' && !visited[i][j])
            {
                upperBound = i, lowerBound = rightBound = 0, leftBound = m, componentSize = 0;
                dfs(i, j);

                if (upperBound)
                    upperBound--;
                if (leftBound)
                    leftBound--;
                if (lowerBound < n - 1)
                    lowerBound++;
                if (rightBound < m - 1)
                    rightBound++;

                prefixSum[upperBound][leftBound] += componentSize;
                if (lowerBound < n - 1 && rightBound < m - 1)
                    prefixSum[lowerBound + 1][rightBound + 1] += componentSize;

                if (lowerBound < n - 1)
                    prefixSum[lowerBound + 1][leftBound] -= componentSize;

                if (rightBound < m - 1)
                    prefixSum[upperBound][rightBound + 1] -= componentSize;

                for (int k = upperBound; k <= lowerBound; k++)
                    rowDots[k] += componentSize;
                for (int k = leftBound; k <= rightBound; k++)
                    colDots[k] += componentSize;
            }
        }
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            prefixSum[i][j] += prefixSum[i - 1][j];

    int maxDots = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j)
                prefixSum[i][j] += prefixSum[i][j - 1];
            maxDots = max(maxDots, rowDots[i] + colDots[j] - (grid[i][j] == '.') - prefixSum[i][j]);
        }
    }

    cout << maxDots << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--)
        solve();

    return 0;
}
