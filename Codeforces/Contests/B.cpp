#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int f = 0;
        int n;
        cin >> n;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {

            int inp;
            cin >> inp;
            if (inp % 3 == 1)
            {
                f = 1;
            }
            pos += inp;
        }
        if (pos % 3 == 0)
        {
            cout << 0 << endl;
        }
        else if (pos % 3 == 2)
        {
            cout << 1 << endl;
        }
        else if (f)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}