#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int N, mod = 1e9 + 7;
    ;
    int solve(int n, int k)
    {
        if (k == 0)
        {
            return 1;
        }

        if (!n)
        {
            return (k == 0);
        }
        int res = solve(n - 1, k - 1) % mod;
        res = (res + (solve(n - 1, k) * 1LL * (N - n) % mod)) % mod;
        return res;
    }

public:
    int rearrangeSticks(int n, int k)
    {
        return solve(n , k);
    }
};

int main()
{

    return 0;
}