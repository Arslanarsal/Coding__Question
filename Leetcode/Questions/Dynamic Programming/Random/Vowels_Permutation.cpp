#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int countVowelPermutation(int n)
    {
        vector<int> pre(5, 1), next(5, 0);
        for (int i = 2; i <= n; i++)
        {
            fill(next.begin(), next.end(), 0);
            next[0] = (pre[1] + 0LL + pre[2] + pre[4]) % mod;
            next[1] = (pre[0] + 0LL + pre[2]) % mod;
            next[2] = (pre[1] + 0LL + pre[3]) % mod;
            next[3] = (pre[2] + 0LL) % mod;
            next[4] = (pre[2] + 0LL + pre[3]) % mod;
            pre = next;
        }
        int ans = (pre[0] + 0LL + pre[1] + pre[2] + pre[3] + pre[4]) % mod;
        return ans;
    }
};

int main()
{

    return 0;
}