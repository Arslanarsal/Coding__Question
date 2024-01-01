#include <iostream>
using namespace std;
long long countStr(int n)
{
    // all a       --> 1
    // 1b and a    --> n
    // 1c and a    --> n
    // 2c and a    --> n*(n-1)/2
    // 1b,1c and a --> n*(n-1)
    // 1b,2c and a --> n(n-1)(n-2)/2

    return 1 + 2 * n + n * (n - 1) / 2 + n * (n - 1) + n * (n - 1) * (n - 2) / 2;
}

int main()
{
    int n = 3;
    cout << countStr(n) << endl; // Output: 19

    return 0;
}
