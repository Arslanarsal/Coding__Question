#include <iostream>
using namespace std;

bool isPowerOf2(int n)
{
    // int a = n & (n - 1);
    // return n && !(a);

    if (n <= 0)
    {
        return false;
    }
    return (n & (n - 1)) == 0;
}

int main()
{
    cout << isPowerOf2(16);
    return 0;
}