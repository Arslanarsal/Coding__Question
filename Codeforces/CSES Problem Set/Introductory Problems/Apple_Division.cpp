#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = LLONG_MAX;

void solve(int i, ll num1, ll num2, int arr[], int &n)
{
    if (i == n)
    {
        ans = min(ans, abs(num1 - num2));
        return;
    }
    solve(i + 1, num1 + arr[i], num2, arr, n);
    solve(i + 1, num1, num2 + arr[i], arr, n);
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    solve(0, 0, 0, arr, n);
    cout << ans << "\n";

    return 0;
}