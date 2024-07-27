#include <bits/stdc++.h>
using namespace std;

#define int ll

using ll = long long;
using pii = pair<int, int>;

const int N = (1 << 18) + 20, C = 18 + 2;
int n, c, k;
int cnt[C];
bool bad[N];
string s;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c >> k;
        cin >> s;

        for (int i = 0; i < (1 << c); i++)
            bad[i] = false;
        for (int i = 0; i < c; i++)
            cnt[i] = 0;

        int cur_mask = 0;

        for (int i = 0; i < k - 1; i++)
        {
            int ch = s[i] - 'A';
            if (!cnt[ch])
                cur_mask += (1 << ch);
            cnt[ch]++;
        }

        for (int i = k - 1; i < n; i++)
        {
            int ch = s[i] - 'A';
            if (!cnt[ch])
                cur_mask += (1 << ch);
            cnt[ch]++;

            bad[cur_mask] = true;

            ch = s[i - k + 1] - 'A';
            cnt[ch]--;
            if (!cnt[ch])
                cur_mask -= (1 << ch);
        }

        bad[(1 << (s[n - 1] - 'A'))] = true;

        int ans = c;
        for (int mask = 0; mask < (1 << c); mask++)
        {
            if (!bad[mask])
            {
                ans = min(ans, c - __builtin_popcount(mask));
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    if (!(mask >> i & 1))
                    {
                        bad[mask + (1 << i)] = true;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}