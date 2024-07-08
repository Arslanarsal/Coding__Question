#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x = i * i;
        ll y = (i - 1) * (i - 2);

        cout << ((x * (x - 1)) /2)  - (4 * y) << "\n";
    }

    return 0;
}