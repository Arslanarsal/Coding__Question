#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (a >= b)
        {
            cout << static_cast<long long>(a) * n << endl;
            continue;
        }

        int k = min(n - 1, b - a - 1);

        long long pr = 0;
        if (k >= 0)
        {
            pr = static_cast<long long>(k + 1) * (b - k + b) / 2;
        }

        int rem = n - k - 1;
        if (rem > 0)
        {
            pr += static_cast<long long>(a) * rem;
        }

        cout << pr << endl;
    }
    return 0;
}