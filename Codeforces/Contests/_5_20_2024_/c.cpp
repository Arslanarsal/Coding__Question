#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long long ans = 0;
        int v[n];
        for (int i = 0; i < n; i++)
            cin >> v[i];

        map<pii, int> mp1, mp2, mp3;
        map<pair<int, pii>, int> gen;
        for (int i = 0; i < n - 2; i++)
        {
            int val = gen[{v[i], {v[i + 1], v[i + 2]}}];
            ans += mp1[{v[i], v[i + 1]}] - val;
            ans += mp2[{v[i], v[i + 2]}] - val;
            ans += mp3[{v[i + 1], v[i + 2]}] - val;

            mp1[{v[i], v[i + 1]}]++;
            mp2[{v[i], v[i + 2]}]++;
            mp3[{v[i + 1], v[i + 2]}]++;
            gen[{v[i], {v[i + 1], v[i + 2]}}]++;
        }
        cout << ans << "\n";
    }

    return 0;
}
