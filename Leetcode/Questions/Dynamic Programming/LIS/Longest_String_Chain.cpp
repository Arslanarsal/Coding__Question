#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(string a, string b)
    {
        if (a.size() + 1 != b.size())
        {
            return false;
        }
        int i = 0, j = 0;
        while (j < b.size())
        {
            if (i < a.size() && a[i] == b[j])
            {
                i++;
            }
            j++;
        }
        return i == a.size();
    }

public:
    int longestStrChain(vector<string> &arr)
    {
        int n = arr.size();

        // Sort the array in ascending order of their lengths
        sort(arr.begin(), arr.end(), [](string a, string b)
             { return a.size() < b.size(); });

        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev_index = 0; prev_index < i; prev_index++)
            {
                if (check(arr[prev_index], arr[i]) && dp[prev_index] + 1 > dp[i])
                {
                    dp[i] = dp[prev_index] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}