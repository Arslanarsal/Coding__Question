#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    int f(int n, int &k)
    {
        if (n <= 1 || n == k)
        {
            return 0;
        }
        int pre = f(n - 1, k);

        if ((n - 1) < k)
        {
            return (pre * 1LL + (n - 1)) % mod;
        }
        return (pre * 1LL + k) % mod;
    }

public:
    int kInversePairs(int n, int k)
    {
        if (k == 0)
        {
            return 1;
        }

        return f(n, k);
    }
};

int main()
{
    Solution sol;
    cout << sol.kInversePairs(3, 0);

    return 0;
}