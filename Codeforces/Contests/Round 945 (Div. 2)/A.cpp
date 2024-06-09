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
        int a, b;
        cin >> a;
        n--;
        int ans = INT_MAX;
        while (n--)
        {
            cin >> b;
            ans = min(ans, max(a, b));
            a = b;
        }
        cout << ans - 1 << "\n";
    }
    return 0;
}