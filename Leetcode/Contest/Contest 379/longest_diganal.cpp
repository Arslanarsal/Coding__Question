#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int n = dimensions.size();
        int idx = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int d = ((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]));
            if (d > ans || (d == ans && dimensions[i][0] * dimensions[i][1] > idx))
            {
                ans = d;
                idx = dimensions[i][0] * dimensions[i][1];
            }
        }
        return idx;
    }
};

int main()
{

    return 0;
}