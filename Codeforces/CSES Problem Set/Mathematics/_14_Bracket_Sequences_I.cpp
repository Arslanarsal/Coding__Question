#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
int n;
int N = 2 * 1e6 + 2;
vector<int> bin;

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
    cin >> n;
    if (n & 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    n = n / 2;
    bin.resize(N);
    bin[0] = 1;
    for (int i = 1; i < N; i++)
    {
        bin[i] = (i * bin[i - 1]) % mod;
    }

    int n2 = bin[2 * n];
    n2 = (n2 * solve(bin[n + 1], mod - 2)) % mod;
    n2 = (n2 * solve(bin[n], mod - 2)) % mod;

    cout << n2 << "\n";

    return 0;
}
