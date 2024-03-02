#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    int n = s.size();
    if (s[0] > '4' && s[0] < '9')
    {
        s[0] = '9' - s[0] + '0';
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] > '4')
        {
            s[i] = '9' - s[i] + '0';
        }
    }
    cout << s;

    return 0;
}