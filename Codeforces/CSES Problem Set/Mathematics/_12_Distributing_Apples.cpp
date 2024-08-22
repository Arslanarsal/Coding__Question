#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
vector<int> bin(2 * 1e6 + 2);

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
    for (int i = 1; i < 2 * 1e6 + 2; i++)
    {
        bin[i] = (i * bin[i - 1]) % mod;
    }
    int n, m;
    cin >> n >> m;
    int a = m + n - 1;
    int b = n - 1;

    // Compute C(a, b) = a! / (b! * (a-b)!)
    int result = (bin[a] * solve(bin[b], mod - 2)) % mod;
    result = (result * solve(bin[a - b], mod - 2)) % mod;

    cout << result << "\n";

    return 0;
}
