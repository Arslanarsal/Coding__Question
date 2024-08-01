#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int idx, vector<vector<int>> &books, int &shelfWidth, vector<int> &dp)
    {
        if (idx >= books.size())
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int ans = INT_MAX, thick = 0, maxheight = books[idx][1], i = idx, n = books.size();
        int j = idx;
        while (i < n && thick + books[i][0] <= shelfWidth)
        {
            thick += books[i][0];
            maxheight = max(maxheight, books[i][1]);
            int ret = solve(i + 1, books, shelfWidth, dp);
            ans = min(ans, maxheight + ret);
            i++;
        }
        return dp[idx] = ans;
    }

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        // vector<int> dp(n + 1, -1);
        // return solve(0, books, shelfWidth, dp);

        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--)
        {
            int ans = INT_MAX, thick = 0, maxheight = books[idx][1], i = idx;
            int j = idx;
            while (i < n && thick + books[i][0] <= shelfWidth)
            {
                thick += books[i][0];
                maxheight = max(maxheight, books[i][1]);
                ;
                ans = min(ans, maxheight + dp[i + 1]);
                i++;
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}