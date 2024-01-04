#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const ll mod = 1e9 + 7;

int main()
{
    ios
#ifndef ONLINE_JUDGE
#endif
        ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for (ll i = 0; i < k; i++)
        {
            v.push_back(n - i);
        }
        for (ll i = 0; i < (n - k); i++)
        {
            v.push_back(i + 1);
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}