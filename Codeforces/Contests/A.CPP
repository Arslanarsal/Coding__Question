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
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            if (inp > 0)
            {
                pos += inp;
            }
            else
            {
                pos += (inp * -1);
            }
        }
        cout << pos << "\n";
    }
    return 0;
}