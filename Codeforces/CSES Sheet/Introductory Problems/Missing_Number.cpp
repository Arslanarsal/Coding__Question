// Leandro Eliecer Vazquez Rivero    IPU:Ramon Infante Garcia    G:12mo
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(nullptr);             \
    cout.tie(nullptr);            \
    cout.setf(ios::fixed);        \
    cout.precision(0); // srand(time(NULL));
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define int long long
#define fs first
#define sd second
#define rsz resize
#define en '\n'

int32_t main()
{
    fast int n, v, x;
    cin >> n;
    v = (n * (n + 1)) / 2;
    --n;

    while (n--)
    {
        cin >> x;
        v -= x;
    }

    cout << v;
    return 0;
}