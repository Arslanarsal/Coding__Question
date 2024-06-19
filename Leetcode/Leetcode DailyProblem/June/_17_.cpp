#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int a = 0;
        int b = sqrt(c);
        while (a <= b)
        {
            int sum = (a * a) + (b * b);
            if (sum == c)
            {
                return true;
            }
            (sum < c) ? a++ : b--;
        }
        return false;
    }
};

int main()
{

    return 0;
}