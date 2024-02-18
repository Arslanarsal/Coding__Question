#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << n << " ";

    while (n > 1)
    {
        if (n & 1)
        {
            n = 3 * n + 1;  
            cout << n << " ";
        }
        else
        {
            n /= 2;
            cout << n << " ";
        }
    }

    return 0;
}
