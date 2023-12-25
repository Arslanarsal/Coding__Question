#include <bits/stdc++.h>
using namespace std;

int minOperations(string s)
{
    int n = s.size();
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((!(i & 1)) && s[i] == '1')
        {
            n1++;
        }
        else if ((i & 1) && s[i] == '0')
        {
            n1++;
        }
        else if ((i & 1) && s[i] == '1')
        {
            n2++;
        }
        else
        {
            n2++;
        }
    }
    return min(n1, n2);
}

int main()
{

    return 0;
}