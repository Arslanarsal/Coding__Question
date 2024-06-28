#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y;
        x = max(a, max(b, c));
        y = min(a, min(b, c));

        cout << x - y << "\n";
    }

    return 0;
}