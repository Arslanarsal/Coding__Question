#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; i++)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.strStr("gffgggg", "gfg");

    return 0;
}