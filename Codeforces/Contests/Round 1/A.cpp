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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = INT_MIN;
        for (int i = 0; i < n; i += 2)
        {
            ans = max(ans, arr[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}