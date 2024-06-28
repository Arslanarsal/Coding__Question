#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long ans;
        if (n <= 2)
        {
            if (s[0] == '0')
            {
                cout << s[1];
            }
            else
            {
                cout << s;
            }
        }
        if (n == 3)
        {
            if (s[0] == '0' || s[2] == '0')
            {
                cout << "0";
            }
            else
            {
                cout << s;
            }
        }
    }

    return 0;
}