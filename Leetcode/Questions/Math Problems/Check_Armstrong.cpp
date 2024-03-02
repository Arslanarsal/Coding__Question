#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n)
{
    int m = n;
    int k = 0;
    while (m)
    {
        m /= 10;
        k++;
    }
    m = n;
    int ans = 0;
    while (m)
    {
        int temp = m % 10;
        m /= 10;
        ans = ans + pow(temp, k);
    }
    return ans == n;
}
int main()
{
    // cout << (2 ^ 3);
    cout << checkArmstrong(1634);
    return 0;
}