#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
int n, N = 1e6 + 2;
vector<int> fact;

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
    fact.resize(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    cin >> n;
    int a = 0, b = 0;

    string s;
    cin >> s;
    int m = s.size();

    for (int i = 0; i < m; i++)
    {
        if (s[i] == '(')
        {
            b++;
        }
        else
        {
            b--;
        }
        a++;
    }
    // cout << b << "\n";
    if (b < 0 || b > n / 2)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (m == n)
    {
        cout << 1 << "\n";
        return 0;
    }
    int n1 = n - a;
    int r1 = -b;

    r1 = (n1 - r1);

    if (r1 & 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    r1 = r1 / 2;

    if (r1 < 0 || r1 > n1)
    {
        cout << 0 << "\n";
        return 0;
    }

    int n2 = n1;

    int r2 = (-b) - ((2 * (-b)) - b);
    r2 = (n2 - r2);
    // if (r2 & 1)
    // {
    //     cout << 0 << "\n";
    //     return 0;
    // }
    r2 = r2 / 2;
    if (r2 < 0 || r2 > n2)
    {
        cout << 0 << "\n";
        return 0;
    }

    int ans1 = (fact[n1] * solve(fact[r1], mod - 2)) % mod;
    ans1 = (ans1 * solve(fact[n1 - r1], mod - 2)) % mod;

    int ans2 = (fact[n2] * solve(fact[r2], mod - 2)) % mod;
    ans2 = (ans2 * solve(fact[n2 - r2], mod - 2)) % mod;

    int result = (ans1 - ans2 + mod) % mod;

    cout << result;
    return 0;
}
