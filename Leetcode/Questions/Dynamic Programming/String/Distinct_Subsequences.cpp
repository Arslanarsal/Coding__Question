#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
    }
};

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> sum(n, vector<int>(m, 0));
    sum = dp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            sum[j][i] = sum[j + 1][i] + sum[j][i];
            cout << sum[j + 1][i] + sum[j][i] << " ";
        }
        cout << sum[0][i] << " ";
        cout << endl;
    }
}

int main()
{
    string str1 = "babgbag", str2 = "bag";
    longestCommonSubsequence(str1, str2);

    return 0;
}