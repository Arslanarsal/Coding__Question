#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (a && b--)
    {
        int temp = a % 10;
        a = a / 10;
        if (temp--)
        {
            a = (a * 10) + temp;
        }

    }
    cout << a << "\n";

    return 0;
}