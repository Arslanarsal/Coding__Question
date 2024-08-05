#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = 1;
        while (b)
        {
            if (b & 1)
            {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b = b >> 1;
        }
        cout << ans << "\n";
    }

    return 0;
}