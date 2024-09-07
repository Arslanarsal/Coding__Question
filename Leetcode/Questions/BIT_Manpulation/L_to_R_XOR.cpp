#include <bits/stdc++.h>
using namespace std;
// int findXOR(int L, int R)
// {
//     int ans = 0;
//     for (int i = L; i <= R; i++)
//     {
//         ans ^= i;
//     }
//     return ans;
// }

/*
    Time Complexity: O(1)

    Space Complexity: O(1)

*/

// Function to compute xor of number 1 to 'N'.
int xor1toN(int N)
{
    if (N % 4 == 0)
        return N;
    if (N % 4 == 1)
        return 1;
    if (N % 4 == 2)
        return N + 1;
    return 0;
}

// Function to compute xor of number 'L' to 'R'.
int findXOR(int L, int R)
{

    // Compute xor of 1 to L-1.
    int x = xor1toN(L - 1);

    // Compute xor of 1 to R.
    int y = xor1toN(R);
    return x ^ y;
}
int main()
{
    cout << findXOR(3, 5) << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << xor1toN(i) << " ";
    }

    return 0;
}