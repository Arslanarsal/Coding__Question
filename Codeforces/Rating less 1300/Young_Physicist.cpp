#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, ans = 0;
    cin >> t;
    while (t--)
    {
        cin >> a;
        ans += a;
        cin >> a;
        ans += a;
        cin >> a;
        ans += a;
    }

    if (ans)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}