#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

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
=======
// #define int long long
#define pi (3.141592653589)
#define mod 1000000007
// #define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

vector<string> v;
int n, m;

int dist[1001][1001];
int d[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        rep(i, 1001) rep(j, 1001) dist[i][j] = -1;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            v.pb(x);
        }
        int x, y, c1, c2;
        queue<vector<int>> q;
        rep(i, n)
        {
            rep(j, m)
            {
                if (v[i][j] == 'M')
                    q.push({i, j, 0});
                if (v[i][j] == 'A')
                    c1 = i, c2 = j;
            }
        }
        x = c1, y = c2;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int x = curr[0], y = curr[1], steps = curr[2];
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || dist[x][y] != -1)
                continue;
            dist[x][y] = steps;
            rep(i, 4)
            {
                int cx = x + dx[i], cy = y + dy[i];
                q.push({cx, cy, steps + 1});
            }
        }
        string ans;
        while (!q.empty())
            q.pop();
        q.push({x, y, 0, 0});
        rep(i, 1001) rep(j, 1001) d[i][j] = -1;
        bool c = false;
        int p[n + 1][m + 1];
        memset(p, 0, sizeof(p));
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int x = curr[0], y = curr[1], steps = curr[2], dir = curr[3];
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 and dist[x][y] <= steps))
                continue;
            if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
            {
                p[x][y] = dir;
                while (x != c1 or y != c2)
                {
                    if (p[x][y] == 0)
                        ans += 'L', y++; 
                    else if (p[x][y] == 1)
                        ans += 'R', y--;
                    else if (p[x][y] == 2)
                        ans += 'U', x++;
                    else
                        ans += 'D', x--;
                }
                reverse(ans.begin(), ans.end());
                c = true;
                break;
            }
            d[x][y] = steps;
            p[x][y] = dir;
            rep(i, 4)
            {
                int cx = x + dx[i], cy = y + dy[i];
                q.push({cx, cy, steps + 1, i});
            }
        }
        if (c)
        {
            cout << "YES" << endl
                 << ans.size() << endl
                 << ans;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
>>>>>>> 612afbf91b3e5e60d4bf1d147177866db4ca57f6
