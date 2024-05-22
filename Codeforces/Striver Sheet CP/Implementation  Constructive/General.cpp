#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int a = INT_MAX;
    int b = INT_MIN;
    int minidx = 0;
    int maxidx = 0;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        if (x > b)
        {
            b = x;
            maxidx = i;
        }
        if (x <= a)
        {
            a = x;
            minidx = i;
        }
    }
    int ans = 0;
    ans += (maxidx) + (t - minidx-1);
    if (maxidx > minidx)
    {
        ans--;
    }
    cout << ans << "\n";

    return 0;
}