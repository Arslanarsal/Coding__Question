#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void LPS(string str, vector<int> &lps)
    {
        int n = str.size();
        lps[0] = 0;
        int lenght = 0;
        int i = 1;
        while (i < n)
        {
            if (str[i] == str[lenght])
            {
                lenght++;
                lps[i] = lenght;
                i++;
            }
            else if (lenght != 0)
            {
                lenght = lps[lenght - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m);

        LPS(needle, lps);
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else if (haystack[i] != needle[j] && j != 0)
            {
                j = lps[j - 1]; 
            }  
            else
            {
                i++;
            }

            if (j == m)
            {
                return i - j;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}