#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, input;
        cin >> n >> x;
        int pre = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> input;
            ans = max(ans, input - pre);
            pre = input;
        }
        ans = max(ans, ((x - input) * 2));
        cout << ans << "\n";
    }

    return 0;
}