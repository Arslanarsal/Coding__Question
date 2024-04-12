#include <bits/stdc++.h>
using namespace std;

string moreSubsequence(int n, int m, string a, string b)
{
    int i = 1, j = 1;
    int x = 1, y = 1;
    while (i < n || j < m)
    {
        if (i < n && a[i] != a[i - 1])
        {
            x++;
        }
        if (j < m && b[j] != b[j - 1])
        {
            y++;
        }
        i++;
        j++;
    }
    if (x >= y)
    {
        return a;
    }
    return b;
}

int main()
{

    return 0;
}