#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ld long double
const int mod = 1e9 + 7;

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans = ans ^ x;
        }
        if (ans)
        {
            cout << "first\n";
        }
        else
        {
            cout << "second\n";
        }
    }

    return 0;
}