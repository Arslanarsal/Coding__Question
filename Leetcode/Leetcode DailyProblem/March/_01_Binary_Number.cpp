#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int coun = count(s.begin(), s.end(), '1');
        string ans(s.size(), '0');
        ans[s.size() - 1] = '1';
        coun--;
        for (int i = 0; i < coun; i++)
        {
            ans[i] = '1';
        }
        return ans;
    }
};

int main()
{

    return 0;
}