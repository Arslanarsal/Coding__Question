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
        int arr[n + 2][3][2];
        // memset(arr, -1, sizeof(arr));
        memset(arr, 0, sizeof(arr));
        // return solve(1, 0, 0, n, arr);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr[n + 1][i][j] = 1;
            }
        }
        for (int i = n; i > 0; i--)
        {
            for (int l = 2; l >= 0; l++)
            {
                for (int a = 1; a >= 0; a++)
                {
                    int ret = 0;
                    ret = (ret * 1LL + arr[i + 1][a][0]) % mod;
                    if (a == 0)
                    {
                        ret = (ret * 1LL + arr[i + 1][1][0]) % mod;
                    }
                    if (l < 2)
                    {
                        ret = (ret * 1LL + arr[i + 1][a][l + 1]) % mod;
                    }
                    arr[i][l][a] = ret;
                }
            }
        }

        
        return arr[0][0][0];
    }
};

int main()
{

    return 0;
}