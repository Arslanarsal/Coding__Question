#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        sort(jobDifficulty.begin(), jobDifficulty.end());
        int ans = jobDifficulty[n - 1];
        for (int i = 0; i < d - 1; i++)
        {
            ans += jobDifficulty[i];
        }
        return ans;
    }
};

int main()
{

    return 0;
}