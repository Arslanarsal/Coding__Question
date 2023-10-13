#include <bits/stdc++.h>
using namespace std;

int differenceOfSums(int n, int m)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % m)
        {
            sum1 += i;
        }
        else
        {
            sum2 += i;
        }
    }
    return sum1 - sum2;
}
int main()
{
    
    cout << differenceOfSums(5, 1);

    return 0;
}