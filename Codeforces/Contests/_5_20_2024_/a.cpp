#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        int flage = false;
        if (y & 1)
        {
            flage = true;
            y++;
        }
        int ans = y / 2;

        int once = ans * 7;
        if (flage)
        {
            once += 4;
        }
        if (once < x)
        {
            ans += ((x - once) / 15);
            if ((x - once) % 15)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}