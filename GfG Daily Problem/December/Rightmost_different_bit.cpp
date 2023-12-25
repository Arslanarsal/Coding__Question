#include <bits/stdc++.h>
using namespace std;

int posOfRightMostDiffBit(int m, int n)
{
    for (int i = 0; i < 32; i++)
    {
        if (((m >> i) & 1) != ((n >> i) & 1))
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    cout << posOfRightMostDiffBit(0, 0);

    return 0;
}