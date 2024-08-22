#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
vector<int> bin(1e6 + 2);

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
    bin[1] = 1;
    bin[2] = 2;
    for (int i = 3; i < 1e6 + 2; i++)
    {
        bin[i] = (i * bin[i - 1]) % mod;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b > a)
        {
            cout << "0\n"; // Binomial coefficient C(a, b) is 0 if b > a
            continue;
        }
        int p = bin[a];
        int q = (bin[b] * bin[a - b]) % mod;
        q = solve(q, mod - 2);
        cout << ((p * q) % mod) << "\n";
    }

    return 0;
}