#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long mod = 1e9 + 7;

    int solve(int i, int t, vector<string> &words, string &target, vector<vector<int>> &dp, vector<vector<int>> &freq)
    {
        if (t == target.size())
        {
            return 1;
        }
        if (i >= words[0].size())
        {
            return 0;
        }

        if (dp[i][t] != -1)
        {
            return dp[i][t];
        }

        
        long long notPick = solve(i + 1, t, words, target, dp, freq);

       
        long long match = freq[i][target[t] - 'a'];
        long long pick = 0;
        if (match)
        {
            pick = (match * solve(i + 1, t + 1, words, target, dp, freq)) % mod;
        }

        // Total ways = ways by picking + ways by not picking
        return dp[i][t] = (pick + notPick) % mod;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        int n = words[0].size();
        int m = target.size();

        // Precompute frequency of each character in each column
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            for (const auto &word : words)
            {
                freq[i][word[i] - 'a']++;
            }
        }

        // DP array initialized to -1 (uncomputed states)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, words, target, dp, freq);
    }
};

int main()
{

    return 0;
}