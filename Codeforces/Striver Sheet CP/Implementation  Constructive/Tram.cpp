#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int temp = 0;
    int ans = 0;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        temp -= a;
        temp += b;
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}