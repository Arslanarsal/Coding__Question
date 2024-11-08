#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1001;
const int mxM = 101;
const int mxK = 26;
const int mod = 1e9 + 7;

int kmp[mxN];

void calc(string &s)
{
    kmp[0] = 0;
    for (int i = 1; i < (int)s.size(); i++)
    {
        int trymatch = kmp[i - 1];
        while (true)
        {
            if (s[trymatch] == s[i])
            {
                kmp[i] = trymatch + 1;
                break;
            }
            else if (trymatch)
            {
                trymatch = kmp[trymatch - 1];
            }
            else
            {
                kmp[i] = 0;
                break;
            }
        }
    }
}

ll dp[mxN][mxM];
bool done[mxN][mxM];

ll solve(int i, int n, int j, string &s)
{
    if (done[i][j])
        return dp[i][j];
    done[i][j] = true;
    if (i == n)
        return dp[i][j] = (j == (int)s.size() ? 1 : 0);
    if (j == (int)s.size())
    {
        return dp[i][j] = (mxK * solve(i + 1, n, j, s)) % mod;
    }
    ll ans = 0;
    int t;
    for (int k = 0; k < mxK; k++)
    {
        t = j;
        while (true)
        {
            if (k == s[t] - 'A')
            {
                t++;
                break;
            }
            else if (t)
            {
                t = kmp[t - 1];
            }
            else
                break;
        }
        ans += solve(i + 1, n, t, s);
        ans %= mod;
    }
    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    calc(s);
    cout << solve(0, n, 0, s);
}