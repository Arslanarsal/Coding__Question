#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // struct pair_hash
    // {
    //     template <class T1, class T2>
    //     size_t operator()(const pair<T1, T2> &p) const
    //     {
    //         auto hash1 = hash<T1>{}(p.first);
    //         auto hash2 = hash<T2>{}(p.second);
    //         return hash1 ^ (hash2 << 1); // Combining the two hashes
    //     }
    // };

    int solve(int n, vector<int> &nums, vector<bool> &visit, unordered_map<vector<bool>, int> &dp)
    {
        int m = nums.size();
        // if (n > m / 2)
        // {
        //     return 0;
        // }
        if (dp.count(visit))
        {
            return dp[visit];
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (!visit[i])
            {
                for (int j = i + 1; j < m; j++)
                {
                    if (!visit[j])
                    {

                        int a = nums[i], b = nums[j];
                        visit[i] = false, visit[j] = false;
                        int ret = solve(n + 1, nums, visit, dp);
                        visit[i] = true, visit[j] = true;
                        int temp = n * __gcd(a, b);
                        ans = max(ans, temp + ret);
                    }
                }
            }
        }

        return dp[visit] = ans;
    }

public:
    int maxScore(vector<int> &nums)
    {
        unordered_map<vector<bool>, int> dp;
        int n = nums.size();
        vector<bool> visit(n, true);
        return solve(1, nums, visit, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2};
    sol.maxScore(v);

    return 0;
}

class Solution
{
public:
    int n;

    int solve(vector<int> &nums, int mask, int operation, vector<int> &memo)
    {
        if (2 * operation == nums.size())
            return 0;

        if (memo[mask] != -1)
        {
            return memo[mask];
        }

        int maxScore = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                if (((mask >> i) & 1) == 1 || ((mask >> j) & 1) == 1)
                    continue;

                int newMask = mask | (1 << i) | ((1 << j));

                int currScore = (operation + 1) * __gcd(nums[i], nums[j]);

                int remainingScore = solve(nums, newMask, operation + 1, memo);

                maxScore = max(maxScore, currScore + remainingScore);
            }
        }

        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int> &nums)
    {
        n = nums.size();

        int memosize = 1 << n;

        vector<int> t(memosize, -1);

        return solve(nums, 0, 0, t);
    }
};