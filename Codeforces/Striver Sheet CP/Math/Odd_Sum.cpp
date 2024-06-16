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
        int even = 0, odd = 0;
        int ans = 0;
        while (n--)
        {
            int a;
            cin >> a;
            ans += a;
            if (a & 1)
            {
                odd = 1;
            }
            else
            {
                even = 1;
            }
        }
        if (ans & 1)
        {
            cout << "yes\n";
        }
        else if (even && odd)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}