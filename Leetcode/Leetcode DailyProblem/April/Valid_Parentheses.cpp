#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(string s)
    {
        int k = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (k < 0)
            {
                return false;
            }
            else if (s[i] == '(')
            {
                k++;
            }
            else if (s[i] == ')')
            {
                k--;
            }
        }
        return k == 0;
    }

    string minRemoveToMakeValid(string s, int i, int n)
    {
        if (check(s))
        {
            return s;
        }
        for (int j = i; j < n; j++)
        {

        }
    }

public:
    string minRemoveToMakeValid(string s)
    {
    }
};

int main()
{

    return 0;
}