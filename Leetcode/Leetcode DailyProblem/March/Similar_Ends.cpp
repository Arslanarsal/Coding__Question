#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {

            if (s[i] == s[j])
            {
                int k = i;
                while (s[i] == s[i+1] && i <  j)
                {
                    /* code */
                }
            }
        }
    }
};

int main()
{

    return 0;
}