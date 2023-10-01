#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0)
            return num.substr(0, i + 1);
    }
    return "";
}

string longestCommonPrefix(vector<string> &strs)
{
    if (!strs.size())
    {
        return "";
    }
    string ans = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;
        int n = ans.length();
        while (j < n)
        {
            if (ans[j] != strs[i][j])
            {
                ans.erase(j);
                break;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    // string s = "123456789";
    // cout << largestOddNumber(s);

    vector<string> vs = {"dog","racecar","car"};
    cout << longestCommonPrefix(vs);
    return 0;
}