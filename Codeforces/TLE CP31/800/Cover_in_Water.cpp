#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int cur = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                cur++;
            }
            if (cur > 2)
            {
                ans = 2;
                break;
            }
            if (s[i] == '#')
            {
                ans += cur;
                cur = 0;
            }
        }
        if (cur < 3 && s[n - 1] == '.')
        {
            ans += cur;
        }
        cout << ans << "\n";
    }

    return 0;
}