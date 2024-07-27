#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // int f(int idx, vector<vector<int>> &jobs, int n, vector<int> &startTime, vector<int> &dp)
    // {
    //     if (idx == n)
    //     {
    //         return 0;
    //     }
    //     if (dp[idx] != -1)
    //     {
    //         return dp[idx];
    //     }
    //     int nextidx = lower_bound(startTime.begin(), startTime.end(), jobs[idx][1]) - startTime.begin();
    //     int ans = max(f(idx + 1, jobs, n, startTime, dp), jobs[idx][2] + f(nextidx, jobs, n, startTime, dp));
    //     return dp[idx] = ans;
    // }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        // vector<int> dp(n + 1, -1);
        vector<int> dp(n + 1, 0);
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < n; i++)
        {
            startTime[i] = jobs[i][0];
        }

        for (int idx = n - 1; idx >= 0; idx--)
        {
            int nextidx = lower_bound(startTime.begin(), startTime.end(), jobs[idx][1]) - startTime.begin();
            int ans = max(dp[idx + 1], jobs[idx][2] + dp[nextidx]);
            dp[idx] = ans;
        }
        return dp[0];

        // return f(0, jobs, n, startTime, dp);
    }
};

int main()
{

    return 0;
}