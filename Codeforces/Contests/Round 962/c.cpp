#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

const int N = 2e5 + 20;
int n, q;
string s[2];

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;
        cin >> s[0] >> s[1];
        vector<vector<int>> preA(n + 1, vector<int>(26, 0));
        vector<vector<int>> preB(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++)
        {
            preA[i] = preA[i - 1];
            int j = s[0][i - 1] - 'a';
            preA[i][j]++;

            preB[i] = preB[i - 1];
            j = s[1][i - 1] - 'a';
            preB[i][j]++;
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            long long ans = 0;
            for (int i = 0; i < 26; i++)
            {
                int a = preA[r][i] - preA[l - 1][i];
                int b = preB[r][i] - preB[l - 1][i];
                if (a >= b)
                {
                    ans += a - b;
                }
            }
            cout << ans << "\n";
        }
    }
}