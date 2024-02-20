#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp ,string &s)
{
    if (i == text1.size() || j == text2.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (text1[i] == text2[j])
    {
       s+=text1[i];
        return dp[i][j] = 1 + f(i + 1, j + 1, text1, text2, dp , s);
    }
    return dp[i][j] = max(f(i + 1, j, text1, text2, dp , s), f(i, j + 1, text1, text2, dp ,s));
}

string findLCS(int n, int m, string &s1, string &s2)
{
    string s = "";
    vector<vector<int>> dp(n, vector<int>(m, -1));
     f(0, 0, s1, s2, dp, s);
    return s == "" ? "1" : s;

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (text1[i - 1] == text2[j - 1])
    //         {
    //             dp[i][j] = 1 + dp[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }
    // string res = "";
    // int len = dp[n][m];
    // int indx = len - 1;
    // for (int i = 0; i < len; i++)
    // {
    //     res += "$";
    // }
    // int i = n, j, m;
    // while (i > 0 && j > 0)
    // {
    //     if (text1[i - 1] == text2[j - 1])
    //     {
    //         res[indx] = text1[i - 1];
    //         indx--;
    //         i--;
    //         j--;
    //     }
    //     else if (dp[i - 1][j] > dp[i][j - 1])
    //     {
    //         i--;
    //     }
    //     else
    //     {
    //         j--;
    //     }
    // }
    // return res;
}

int main()
{
    string s = "ababa";
    string s1 = "cbbcad";
    return 0;
}