#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int countOrders(int n)
    {
        long long ans = 1;
        for (int i = 2; i <= n; i++)
        {
            long long spaces = i * 2 - 1;
            long long cur = spaces * (spaces + 1) / 2;
            ans = (ans * cur) % mod;
        }
        return ans;
    }
};

int main()
{

    return 0;
}