#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (2LL * a <= b)
        {
            cout << a << " " << 2LL * a << "\n";
        }
        else
        {
            cout << -1 << " " << -1 << "\n";
        }
    }

    return 0;
}