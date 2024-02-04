#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int j, int &k, vector<int> &v, vector<int> &dp)
    {
        int ans = 0;
        int temp = 0;
        if (j < v.size() && dp[j] != -1)
        {
            return dp[j];
        }

        for (int i = j; i < min(j + k, static_cast<int>(v.size())); i++)
        {
            temp = max(temp, v[i]);
            int ret = f(i + 1, k, v, dp);
            int element = temp * ((i - j) + 1);
            ans = max(ans, element + ret);
        }
        return dp[j] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size() + 1, -1);
        return f(0, k, arr, dp);
    }
};

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int ans = 0;
            int temp = 0;
            int len = 0;

            for (int i = ind; i < min(ind + k, n); i++)
            {
                len++;
                temp = max(temp, arr[i]);
                int element = temp * (i - ind + 1) + dp[i + 1];
                ans = max(ans, element);
            }

            dp[ind] = ans;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}