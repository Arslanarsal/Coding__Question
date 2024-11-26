#include <iostream>
#include <cmath>

using namespace std;

int bi(int n, int r)
{
    int res = 1;
    if (r > n - r)
    {
        r = n - r;
    }
    for (int i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, r, x, y;
        cin >> n >> r >> x >> y;

        int term = bi(n, r - 1) * pow(x, n - r + 1) * pow(y, r - 1);
        cout << term << endl;
    }

    return 0;
}