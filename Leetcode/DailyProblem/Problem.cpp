#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> mp;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            string temp = "s";
            for (int i = 1; i < m; i++)
            {
                if (matrix[i][0] == matrix[i][j])
                {
                    temp += 's';
                }
                else
                {
                    temp += 'b';
                }
            }
            mp[temp]++;
            ans = max(ans, mp[temp]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // sol.canSortArray({18, 3, 8});

    return 0;
}