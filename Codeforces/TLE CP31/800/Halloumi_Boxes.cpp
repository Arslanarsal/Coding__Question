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
        int cur;
        int pre = -1;
        int flage = true;
        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            if (k < 2 && cur < pre)
            {
                flage = false;
            }
            pre = cur;
        }
        if (flage)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}