#include <bits/stdc++.h>
using namespace std;
#define int long long
// Function to find the maximum k such that the sum of first k natural numbers is <= n
int maxK(int n)
{
    // Use the quadratic formula to find the maximum k
    return (-1 + sqrt(1 + 8.0 * n)) / 2;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int n = b - a;
        cout << maxK(n) + 1 << "\n";
    }

    return 0;
}
