#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m, x;

int tria[1000006][26]{};
int counter = 0;
int dp[50001]{};
int endPoint[1000006]{};

void insert(string &s)
{
    int cur = 0;
    for (auto &&c : s)
    {
        if (tria[cur][c - 'a'] == 0)
            tria[cur][c - 'a'] = ++counter;
        cur = tria[cur][c - 'a'];
    }
    endPoint[cur] = 1;
}

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            insert(temp);
        }
        m = s.size();
        dp[m] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            int cnt = 0;
            int ans = 0;
            for (int j = i; j < m; j++)
            {
                if (tria[cnt][s[j] - 'a'] == 0)
                {
                    break;
                }
                cnt = tria[cnt][s[j] - 'a'];
                if (endPoint[cnt])
                {
                    ans = (ans + dp[j + 1]) % mod;
                }
            }
            dp[i] = ans;
        }
        cout << dp[0];
    }

    return 0;
}