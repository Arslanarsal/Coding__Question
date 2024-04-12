#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string removeKdigits(string num, int k)
    {
        string ans = "";
        int n = num.length();
        for (int i = 0; i < n; i++)
        {
            while (ans.size() && ans.back() > num[i] && k)
            {
                ans.pop_back();
                k--;
            }
            if (ans.size() || num[i] != '0')
            {
                ans.push_back(num[i]);
            }
        }
        while (ans.size() && k)
        {
            ans.pop_back();
            k--;
        }
        if (!ans.size())
        {
            return "0";
        }
        return ans;
    }
};

int main()
{

    return 0;
}