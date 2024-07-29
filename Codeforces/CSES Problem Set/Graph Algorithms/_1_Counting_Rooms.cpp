#include <bits/stdc++.h>
using namespace std;

int arr[4] = {-1, 0, 1, 0};
int arr1[4] = {0, 1, 0, -1};

void solve(int i, int j, vector<vector<bool>> &visit, vector<string> &inp)
{
    if (i < 0 || j < 0 || i >= visit.size() || j >= visit[0].size() || visit[i][j])
    {
        return;
    }
    visit[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        if (i + arr[k] >= 0 && j + arr1[k] >= 0 && i + arr[k] < visit.size() && j + arr1[k] < visit[0].size() && inp[i + arr[k]][j + arr1[k]] == '.' && !visit[i + arr[k]][j + arr1[k]])
        {
            solve(i + arr[k], j + arr1[k], visit, inp);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    vector<vector<bool>> vist(n, vector<bool>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (inp[i][j] == '.' && !vist[i][j])
            {
                solve(i, j, vist, inp);
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}