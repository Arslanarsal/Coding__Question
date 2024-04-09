#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int i = 0;
    bool flag = true;
    while (i < n)
    {
        if (!(i & 1))
        {
            for (int j = 0; j < m; j++)
            {
                cout << "#";
            }
        }
        else
        {
            if (flag)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    cout << ".";
                }
                cout << "#";
                flag = false;
            }
            else
            {
                cout << "#";
                for (int j = 1; j < m; j++)
                {
                    cout << ".";
                }
                flag = true;
            }
        }
        cout << "\n";
        i++;
    }

    return 0;
}