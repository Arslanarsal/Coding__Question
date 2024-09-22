#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
int mod = 1e9 + 7;
int find_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int32_t main()
{

    cin >> n >> s;
    int m = n - s.size();
    if (m == 1)
    {
        cout << 52 << "\n";
        return 0;
    }

    int ans = find_pow(26, m);
    if (s.size())
    {
        ans = find_pow(ans, m);
    }
    cout << ans << "\n";

    return 0;
}