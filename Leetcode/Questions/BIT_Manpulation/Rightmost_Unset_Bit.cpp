#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
int setBits(int N)
{
    // Check if there's any unset bits.
    if ((N & (N + 1)) == 0)
        return N;

    // Set the least significant unset bit of ‘N’ to 1 and return.
    return N | (N + 1);
}

int main()
{

    return 0;
}