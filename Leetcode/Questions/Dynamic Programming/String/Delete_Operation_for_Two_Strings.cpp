#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> pre(m + 1, 0), cur(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    cur[j] = 1 + pre[j - 1];
                }
                else
                {
                    cur[j] = max(pre[j], cur[j - 1]);
                }
            }
            pre = cur;
        }
        return pre[m];
    }
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        int a = longestCommonSubsequence(word1, word2);
        int ans = n - a;
        ans += m - a;
        return ans;
    }
};
int main()
{

    return 0;
}