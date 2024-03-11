#include <bits/stdc++.h>
using namespace std;

// int func(int n, int m, int y)
// {
//     int ans = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         ans *= m;
//         if (ans > y)
//         {
//             return 2;
//         }
//     }
//     return ans == y ? 1 : 0;
// }

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int get = func(mid, n, m);
        if (get == 1)
        {
            return mid;
        }
        else if (get == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}