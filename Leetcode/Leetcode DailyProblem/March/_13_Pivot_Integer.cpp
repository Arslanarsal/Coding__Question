#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int x = sqrt(n * (n + 1) / 2);
        if (x - floor(x) == 0)
        {
            return x;
        }
        return -1;
    }
};

int main()
{

    return 0;
}