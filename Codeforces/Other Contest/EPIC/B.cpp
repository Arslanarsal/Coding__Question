#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        long long maxele = 0;
        for (int i = 1; i < n; i++)
        {
            long long temp = max(0, a[i - 1] - a[i]);
            ans += temp;
            maxele = max(maxele, temp);
            a[i] += temp;
        }
        cout << ans + maxele << "\n";
    }

    return 0;
}