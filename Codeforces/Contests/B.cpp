#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                cout << i << " ";
            }
            for (int i = n; i > n / 2; i--)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
