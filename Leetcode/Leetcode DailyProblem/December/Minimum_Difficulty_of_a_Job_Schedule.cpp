#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int f(int i, int d, vector<int> &job, vector<vector<int>> &dp)
    {
        if (d == 1)
        {
            int ans = INT_MIN;
            for (int j = i; j < n; j++)
            {
                ans = max(ans, job[j]);
            }
            return ans;
        }
        if (dp[i][d] != -1)
        {
            return dp[i][d];
        }
        int ans = INT_MAX;
        int max_value = INT_MIN;
        for (int j = i; j <= n - d; j++)
        {
            max_value = max(max_value, job[j]);
            ans = min(ans, max_value + f(j + 1, d - 1, job, dp));
        }
        return dp[i][d] = ans;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return f(0, d, jobDifficulty, dp);
    }
};

class Solution {
public:
    int solve(int job_index, int day_index, int d, vector<int>& jobDifficulty, vector<vector<int> > & dp)
    {
        if(day_index == d - 1)
        {
            int maxDifficulty = 0;
            for(auto i = job_index; i < jobDifficulty.size(); ++i)
                maxDifficulty = max(jobDifficulty[i], maxDifficulty);
            return dp[job_index][day_index] = maxDifficulty;
        }
        if(dp[job_index][day_index]!= -1)
            return dp[job_index][day_index];
        
        int cDifficulty = 0;
        int max_D = 400000;
        for(auto i = job_index; i < jobDifficulty.size() - (d - day_index - 1); ++i)
        {
            cDifficulty = max(jobDifficulty[i], cDifficulty);
            auto solvable = solve(i+1, day_index + 1, d, jobDifficulty, dp);
            max_D = min(cDifficulty + dp[i+1][day_index + 1] , max_D) ;   
        }
        
        return dp[job_index][day_index] = max_D;      
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size())
            return -1;
        vector<vector<int> > dp(jobDifficulty.size(), vector<int>(d, -1));
        return solve(0, 0, d, jobDifficulty, dp);        
    }
};

int main()
{

    return 0;
}