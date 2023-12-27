#include <bits/stdc++.h>
using namespace std;

int integerBreak(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    int product = 1;
    while (n > 4)
    {
        product *= 3;
        n -= 3;
    }
    return (product * n);
}

int main()
{
    cout << integerBreak(4);

    return 0;
}
