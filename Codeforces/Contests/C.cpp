#include <bits/stdc++.h>
using namespace std;

#define int long long
int const N = 2e5 + 5;
int const mod = 1e9 + 7;

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    bool flag = false;
    int pre = 0;
    int a, b;
    for (int i = 0; i < n; i++)
    {

        cin >> a >> b;
        if (a - pre >= s)
        {
            flag = true;
        }
        pre = b;
    }
    if (m - pre >= s)
    {
        flag = true;
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}