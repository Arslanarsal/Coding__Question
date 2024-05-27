#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    int solve(int i, int a, int l, int &n, int arr[][3][2])
    {
        if (i > n)
        {
            return 1;
        }
        if (arr[i][l][a] != -1)
        {
            return arr[i][l][a];
        }

        int ret = 0;
        ret = (ret * 1LL + solve(i + 1, a, 0, n, arr)) % mod;
        if (a == 0)
        {
            ret = (ret * 1LL + solve(i + 1, 1, 0, n, arr)) % mod;
        }
        if (l < 2)
        {
            ret = (ret * 1LL + solve(i + 1, a, l + 1, n, arr)) % mod;
        }
        return arr[i][l][a] = ret;
    }

public:
    int checkRecord(int n)
    {
        int arr[n + 1][3][2];
        memset(arr, sizeof(arr), -1);
        return solve(1, 0, 0, n, arr);
    }
};

int main()
{

    return 0;
}