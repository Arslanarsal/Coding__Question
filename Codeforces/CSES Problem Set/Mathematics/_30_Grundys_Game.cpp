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
        int rem = n % 3;
        bool ans = true;
        if (n == 2 || rem == 1)
        {
            ans = false;
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