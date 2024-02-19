#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n <= 0 ? false : __builtin_popcount(n) == 1 ? true
                                                           : false;
    }
};

int main()
{

    return 0;
}