#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }
        int index = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[i] < 1 + dp[j])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[index]);
        while (hash[index] != index)
        {
            index = hash[index];
            ans.push_back(arr[index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}