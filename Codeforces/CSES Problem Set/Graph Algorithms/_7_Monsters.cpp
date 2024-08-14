#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> grid;
vector<vector<int>> dist;
vector<vector<pair<int, int>>> parent; 

string solvea(int start, int end)
{
    queue<pair<int, int>> q;
    dist[start][end] = 0;
    q.push({start, end});
    parent[start][end] = {-1, -1};

    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    char dir[4] = {'U', 'R', 'D', 'L'};

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ii = i + x[k];
            int jj = j + y[k];

            if (ii >= 0 && ii < N && jj >= 0 && jj < M && grid[ii][jj] == '.' && dist[ii][jj] > (dist[i][j] + 1))
            {
                q.push({ii, jj});
                dist[ii][jj] = dist[i][j] + 1;
                parent[ii][jj] = {i, j};

                if (ii == 0 || ii == N - 1 || jj == 0 || jj == M - 1)
                {
                    string ans = "";
                    int ci = ii, cj = jj;

                    while (parent[ci][cj].first != -1)
                    {
                        int pi = parent[ci][cj].first;
                        int pj = parent[ci][cj].second;

                        for (int d = 0; d < 4; d++)
                        {
                            if (ci == pi + x[d] && cj == pj + y[d])
                            {
                                ans += dir[d];
                                break;
                            }
                        }
                        ci = pi;
                        cj = pj;
                    }
                    reverse(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
    }
    return "";
}

void solve(int start, int end)
{
    queue<pair<int, int>> q;
    dist[start][end] = 0;
    q.push({start, end});

    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ii = i + x[k];
            int jj = j + y[k];

            if (ii >= 0 && ii < N && jj >= 0 && jj < M && grid[ii][jj] == '.' && dist[ii][jj] > (dist[i][j] + 1))
            {
                q.push({ii, jj});
                dist[ii][jj] = dist[i][j] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    N = n;
    M = m;
    grid.resize(n);
    dist.resize(n, vector<int>(m, INT_MAX));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int aa, bb;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                solve(i, j);
            }
            if (grid[i][j] == 'A')
            {
                aa = i;
                bb = j;
            }
        }
    }

    string ans = solvea(aa, bb);
    if (ans.size())
    {
        cout << "YES\n";
        cout << ans.size() << "\n";
        cout << ans;
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
