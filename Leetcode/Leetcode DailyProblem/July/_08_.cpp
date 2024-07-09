#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int n, int &k)
    {
        if (n == 1)
        {
            return 0;
        }
        return (solve(n - 1, k) + k) % n;
    }

public:
    int findTheWinner(int n, int k)
    {
        // return solve(n, k) + 1;
        int pre = 0;

        for (int i = 2; i <= n; i++)
            pre = (pre + k) % i;

        return pre + 1;
    }
};

int main()
{

    return 0;
}