#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        while (x)
        {
            int temp = (x % 10);
            ans = (ans * 10) + temp;
            x = x / 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        return ((int)ans);
    }
};
int main()
{

    return 0;
}