#include <bits/stdc++.h>

using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define int long long

void CoderAbhi27()
{
    int n, k;
    cin >> n >> k;
    if (k % 2)
    {
        cout << "No\n";
        return;
    }
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++)
        a[i] = i;
    k /= 2;
    int x = n - 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (k <= x)
        {
            swap(a[i], a[i + k]);
            k = 0;
            break;
        }
        swap(a[i], a[i + x]);
        k -= x;
        x -= 2;
        if (x <= 0)
            break;
    }
    if (k > 0)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 1; i < n + 1; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int32_t main()
{
    fastIO;
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r" , stdin);
// freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        // cout<<"Case #"<<i<<": ";
        CoderAbhi27();
    }
    return 0;
}