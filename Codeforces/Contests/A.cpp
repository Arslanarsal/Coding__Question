#include <bits/stdc++.h>
using namespace std;
int t, n, q, m, x;

int main()
{

    cin >> t;
    char ch[5] = {'a', 'e', 'i', 'o', 'u'};
    while (t--)
    {
        cin >> n;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            ans += ch[i % 5];
        }
        cout << ans << "\n";
    }

    return 0;
}