#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        int flag = true;
        if (a >b)
        {
           flag = true;
        }else{
            flag = false;
        }
        
        while (a <= n && b <= n)
        {
            if (flag)
            {
                flag = false;
                a += b;
            }
            else
            {
                flag = true;
                b += a;
            }

            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}