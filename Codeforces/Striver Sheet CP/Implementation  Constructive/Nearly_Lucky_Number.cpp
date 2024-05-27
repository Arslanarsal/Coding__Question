#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int a = 0;
    while (n)
    {
        if (n % 10 == 4 || n % 10 == 7)
            a++;

        n = n / 10;
    }
    if (a == 4 || a == 7)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}