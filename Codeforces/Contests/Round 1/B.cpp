#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi inp(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> inp[i];
        }
        vi a(n);
        a[0] = inp[0];
        a[n - 1] = inp[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            a[i] = inp[i] | inp[i - 1];
        }
        bool flag = false;
        for (int i = 0; i + 1 < n; i++)
        {
            if ((a[i] & a[i + 1]) != inp[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
