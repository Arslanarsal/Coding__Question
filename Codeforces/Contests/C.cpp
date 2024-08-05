#include <bits/stdc++.h>
using namespace std;

#define int long long
int const N = 2e5 + 5;
int const mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);
  
    int tm = arr[n - 1];
    int of = -1, on = k + 1;
    for (int i = 0; i < n; ++i)
    {
        int d = tm - arr[i];
        if ((d / k) % 2)
            of = max(of, k - (d % k));
        else
            on = min(on, k - (d % k));
    }
    // cout<<on<<' '<<of<<endl;
    if (of == -1)
    {
        cout << tm << endl;
        // return;
    }
    else if (on <= of)
    {
        cout << -1 << endl;
        // return;
    }
    else
        cout << tm + of << endl;
    // cout<<endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}