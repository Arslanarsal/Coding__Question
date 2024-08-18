#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int n = points.size(), m = points[0].size();
        vector<long long> pre(m), cur(m);
        for (int j = 0; j < m; j++)
        {
            pre[j] = points[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            vector<long long> left(m, 0), right(m, 0);
            left[0] = points[i - 1][0];
            for (int j = 1; j < m; j++)
            {
                left[j] = max(left[j - 1] - 1, pre[j]);
            }
            right[m - 1] = points[i - 1][m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                right[j] = max(right[j + 1] - 1, pre[j]);
            }

            for (int j = 0; j < m; j++)
            {
                pre[j] = points[i][j] + 0LL + max(left[j], right[j]);
            }
        }
        long long ans = 0;
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, pre[j]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}