#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a = -1, b = -1;
        int pre = 0;
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            int cur = 0;

            for (int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '#' && b == -1)
                {
                    k = i;
                    b = j;
                }
                else if (ch == '#')
                {
                    cur++;
                }
            }
            if (cur < pre && a == -1)
            {
                a = i - 1;
            }
            if (cur)
            {
                pre = cur;
            }
        }
        if (a == -1)
        {
            cout << k << " " << b << "\n";
        }
        else
        {
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}
