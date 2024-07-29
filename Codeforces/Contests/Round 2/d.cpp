#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int c = (s[i - 1] == '1') ? 1 : -1;
            pre[i] = pre[i - 1] + c;
        }
        long long ans = 0;
        int mod = 1e9 + 7;
        unordered_map<long long, long long> mp;
        for (int i = 0; i <= n; i++)
        {
            long long precount = pre[i];

            long long preleft = mp[precount];

            long long r = n - i + 1;

            ans += (preleft * r) % mod;

            mp[precount] += i + 1;
        }
        cout << ans % mod << "\n";
    }

    return 0;
}
