#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int N, ki, tg;
    vector<vector<long long>> dp;
    const int MOD = 1e9 + 7;

public:
    int numMusicPlaylists(int N, int goal, int k)
    {
        ki = k;
        tg = goal;
        dp = vector<vector<long long>>(N + 1, vector<long long>(goal + 1, 0));

        // Base case: if you use exactly N songs to create a playlist of length N, there's 1 way.
        dp[N][goal] = 1;

        for (int n = N; n >= 0; n--)
        {
            for (int g = goal; g >= 0; g--)
            {
                if (g == goal && n == N)
                    continue; // Skip the base case already set

                long long ans = 0;
                // Case 1: Add a new song to the playlist
                if (n < N && g < goal)
                {
                    ans += (N - n) * dp[n + 1][g + 1] % MOD;
                }

                // Case 2: Add a song that has been played before (but not in the last k songs)
                if (n > ki && g < goal)
                {
                    ans += (n - ki) * dp[n][g + 1] % MOD;
                }

                dp[n][g] = ans % MOD;
            }
        }
        return dp[0][0];
    }
};

int main()
{

    return 0;
}