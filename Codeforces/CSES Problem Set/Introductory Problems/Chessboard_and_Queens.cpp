#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void solve(int cur, vector<string> &board, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2)
{
    if (cur == 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (board[cur][i] == '.' && !col[i] && !diag1[cur + i] && !diag2[cur - i + 7])
        {
            col[i] = diag1[cur + i] = diag2[cur - i + 7] = true;
            board[cur][i] = 'Q';
            solve(cur + 1, board, col, diag1, diag2);
            col[i] = diag1[cur + i] = diag2[cur - i + 7] = false;
            board[cur][i] = '.';
        }
    }
    return;
}

int main()
{
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    vector<bool> col(8, false);
    vector<bool> diag1(16, false);
    vector<bool> diag2(16, false);

    solve(0, board, col, diag1, diag2);
    cout << ans << "\n";

    return 0;
}
