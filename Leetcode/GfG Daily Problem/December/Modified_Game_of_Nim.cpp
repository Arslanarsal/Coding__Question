#include <bits/stdc++.h>
using namespace std;

int findWinner(int n, int A[])
{
    if (n % 2 == 0)
    {
        return 1;
    }
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val = val ^ A[i];
    }
    if (val == 0)
    {
        return 1;
    }
    return 2;
}

int main()
{

    return 0;
}