#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int a = 0;
        for (auto &&i : nums)
        {
            a ^= i;
        }
        int b = a ^ k;
        int c = 0;
        while (b)
        {
            c += b & 1;
            b >>= 1;
        }
        return c;
    }
};

int main()
{

    return 0;
}