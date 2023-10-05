
#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    // int flip_count = 0;

    // // XOR start and goal to find bits that need flipping
    // int flip_bits = start ^ goal;

    // // Count number of bits that need flipping using built-in function
    // flip_count = __builtin_popcount(flip_bits);

    // return flip_count;

    return __builtin_popcount(start^goal);
}

int main()
{
    cout << minBitFlips(7, 10) << endl;

    return 0;
}