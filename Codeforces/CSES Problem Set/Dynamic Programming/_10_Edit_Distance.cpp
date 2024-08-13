#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<long long>> dp;
// long long solve(int i, int j, string &str1, string &str2)
// {
//     if (i < 0)
//     {
//         return j + 1;
//     }
//     if (j < 0)
//     {
//         return i + 1;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     long long ans = INT_MAX;
//     if (str1[i] == str2[j])
//     {
//         return dp[i][j] = solve(i - 1, j - 1, str1, str2);
//     }
//     ans = min(ans, solve(i - 1, j, str1, str2));
//     ans = min(ans, solve(i, j - 1, str1, str2));
//     ans = min(ans, solve(i - 1, j - 1, str1, str2));

//     return dp[i][j] = ans + 1;
// }

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    N = str1.size();
    M = str2.size();
    // dp.resize(N + 1, vector<int>(M + 1, -1));
    // cout << solve(N - 1, M - 1, str1, str2) << "\n";

    dp.resize(N + 1, vector<long long>(M + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {

            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                long long ans = INT_MAX;
                ans = min(ans, dp[i - 1][j]);
                ans = min(ans, dp[i][j - 1]);
                ans = min(ans, dp[i - 1][j - 1]);
                dp[i][j] = ans + 1;
            }
        }
    }
    cout << dp[N][M] << "\n";

    return 0;
}