#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mat[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int a;
            cin >> a;
            if (a)
            {
                int ans = abs(2 - i);
                ans += abs(2 - j);
                cout << ans;
                return 0;
            }
        }
    }

    return 0;
}