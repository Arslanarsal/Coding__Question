#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor)
    {
        int ans = 1;
        int count = 0;
        int n = corridor.size();
        int k = 0;
        int j = 0;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                k++;
                j = m;
                m = i;
                count++;
            }
            if (k == 3)
            {
                int space = i - j;
                ans = (ans * 1LL * space) % mod;
                k = 1;
            }
        }
        if (count & 1 || !count)
        {
            return 0;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    sol.numberOfWays("SSPPSPS");
    return 0;
}