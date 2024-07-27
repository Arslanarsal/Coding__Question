#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        int i = 0;
        bool flage = true;
        while (k > 0)
        {
            k = k - (n - i);
            ans++;
            if (flage)
            {
                i++;
                flage = false;
            }
            else
            {
                flage = true;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}