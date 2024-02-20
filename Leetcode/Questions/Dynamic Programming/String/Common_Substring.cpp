#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> pre(m + 1, 0), cur(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                cur[j] = 1 + pre[j - 1];
                ans = max(ans, cur[j]);
            }
            else
            {
                cur[j] = 0;
            }
        }
        pre = cur;
    }
    return ans;
}

int main()
{

    return 0;
}