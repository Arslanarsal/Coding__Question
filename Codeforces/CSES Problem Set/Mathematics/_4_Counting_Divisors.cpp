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
        long long ans = 1;

        for (int i = 2; (i * i) <= n; i++)
        {
            if (n % i == 0)
            {
                int temp = 1;
                while (n % i == 0)
                {
                    temp++;
                    n = n / i;
                }
                ans = ans * temp;
            }
        }
        if (n > 1)
        {
            ans = ans * 2;
        }

        cout << ans << "\n";
    }

    return 0;
}