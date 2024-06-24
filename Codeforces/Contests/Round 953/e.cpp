#include <bits/stdc++.h>

using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define int long long
#define ff first
#define ss second

void CoderAbhi27()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s1 = s, t1 = t;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == '0' && s[i + 1] == '0')
            t1[i] = '1';
    }
    vector<pair<int, int>> req(n, {-1, -1});
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '1')
            continue;
        if (t1[i - 1] == '1' && t1[i + 1] == '1')
        {
            s1[i] = '1';
            req[i] = {i - 1, i + 1};
            if (t[i - 1] == '0')
                req[i].ff--;
            if (t[i + 1] == '0')
                req[i].ss++;
        }
    }
    vector<int> pr(n, 0), pr1(n, 0);
    pr[0] = s[0] == '1';
    for (int i = 1; i < n; i++)
        pr[i] = pr[i - 1] + (s[i] == '1');

    for (int i = 1; i < n; i++)
    {
        pr1[i] = pr1[i - 1];
        if (s[i] == '0' && s1[i] == '1')
            pr1[i]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = pr[r];
        if (l > 0)
            ans -= pr[l - 1];

        if (r - l + 1 <= 4)
        {
            for (int i = l; i <= r; i++)
            {
                if (s[i] == '0' && s1[i] == '1' && req[i].ff >= l && req[i].ss <= r)
                    ans++;
            }
            cout << ans << '\n';
            continue;
        }

        for (int i = l; i < l + 2; i++)
            if (s[i] == '0' && s1[i] == '1' && req[i].ff >= l && req[i].ss <= r)
                ans++;
        for (int i = r - 1; i < r + 1; i++)
            if (s[i] == '0' && s1[i] == '1' && req[i].ff >= l && req[i].ss <= r)
                ans++;
        ans += pr1[r - 2] - pr1[l + 1];
        cout << ans << '\n';
    }
}

int32_t main()
{
    fastIO;
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r" , stdin);
// freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        // cout<<"Case #"<<i<<": ";
        CoderAbhi27();
    }
    return 0;
}