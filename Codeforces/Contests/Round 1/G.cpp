#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

const int N = 5e5 + 20;
int t;

int n, p[N];
int a[N], b[N];
vector<int> vecA[N], vecB[N];

int cnt[N], curr[N];
ll ans;

int last[N], res[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        for (int i = 0; i <= n; i++)
        {
            vecA[i].clear();
            vecB[i].clear();
            last[i] = -1;
        }
        ans = 0;

        for (int i = 0; i < n; i++)
        {
            a[i] = p[i];
            b[i] = i + 1;

            int g = __gcd(a[i], b[i]);

            a[i] /= g;
            b[i] /= g;

            vecA[a[i]].push_back(i);
            vecB[b[i]].push_back(i);
        }

        for (int x = 1; x <= n; x++)
        {
            // These numbers need x

            for (int i : vecB[x])
            {
                cnt[a[i]]++;
            }

            for (int y = x; y <= n; y += x)
            {
                for (int i : vecA[y])
                {
                    // These numbers give y to you

                    int val = b[i];

                    if (last[val] != x)
                    {
                        res[val] = 0;
                        for (int j = val; j <= n; j += val)
                            res[val] += cnt[j];

                        last[val] = x;
                    }

                    ans += res[val];
                }
            }

            for (int i : vecB[x])
            {
                cnt[a[i]]--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (b[i] == 1)
                ans--;
        }
        ans /= 2;

        cout << ans << endl;
    }
}