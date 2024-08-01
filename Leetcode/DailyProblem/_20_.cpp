#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (rowSum[i] < colSum[j])
            {
                ans[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                i++;
            }
            else
            {
                ans[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}