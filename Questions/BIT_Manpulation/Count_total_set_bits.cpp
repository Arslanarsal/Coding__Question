#include <bits/stdc++.h>
using namespace std;

// int countSetBits(int N)
// {
//     int ans = 0;
//     // for (int i = 1; i <= N; i++)
//     // {
//     //     for (int j = 31; j >= 0; j--)
//     //     {
//     //         i & (1 << j) ? ans++ : 0;
//     //     }
//     // }
//     for (int i = 1; i <= N; i++)
//     {
//         ans += __builtin_popcount(i);
//     }
//     return ans;
// }

int countSetBits(int N)
{
    // We have 'd' which is the size of repeating window.
    // We are using 'x' to run the loop Log(N) times which is equal to the number of bits in its binary representation.
    int d = 2, ans = 0, x = N;
    while (x)
    {

        // Using the Mathematical formula explained in the Approach.
        ans += ((N + 1) / d) * (d / 2) + max((N + 1) % d - d / 2, 0);

        // Window size double every time we shift to the next left bit.
        d *= 2;
        x /= 2;
    }
    return ans;
}
int main()
{
    cout << countSetBits(5);
    // cout << count(9);

    return 0;
}