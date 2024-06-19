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
        long long a = INT_MIN;
        n--;
        long long x;
        while (n--)
        {
            cin >> x;
            a = max(a, x);
        }
        cin >> x;
        cout << x + a << "\n";
    }

    return 0;
}
