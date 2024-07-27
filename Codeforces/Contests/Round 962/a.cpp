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
        int ans = 0;
        ans += n / 4;
        bool flag = n %= 4;
        ans += flag;
        cout << ans << "\n";
    }

    return 0;
}