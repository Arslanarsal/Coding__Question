#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int m = n;
    int ans = 0;
    while (m)
    {
        int temp = m % 10;
        if (temp != 0 && n % temp == 0)
        {
            ans++;
        }
        m /= 10;
    }
    return ans;
}

int f(int n)
{
    cout << (int)(log10(n) + 1) << endl;
}

int main()
{
    f(10);
    f(10234);
    f(1420);
    f(120);

    return 0;
}