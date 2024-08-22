#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
vector<int> bin(1e6 + 2);
vector<int> freq(26);

int solve(int a, int b)
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
    bin[0] = 1;
    for (int i = 1; i < 1e6 + 2; i++)
    {
        bin[i] = (i * bin[i - 1]) % mod;
    }

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    int ans = bin[n];
    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
        {
            ans = (ans * solve(bin[freq[i]], mod - 2)) % mod;
        }
    }
    cout << ans << "\n";

    return 0;
}