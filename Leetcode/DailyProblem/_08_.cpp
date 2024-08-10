#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> dirt{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> ans;
        int step = 0, d = 0;
        ans.push_back({rStart, cStart});
        while (ans.size() < (rows * cols))
        {
            if (d == 0 || d == 2)
            {
                step++;
            }
            for (int i = 0; i < step; i++)
            {
                rStart += dirt[d][0];
                cStart += dirt[d][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    ans.push_back({rStart, cStart});
                }
            }
            d = (d + 1) % 4;
        }
        return ans;
    }
};

int main()
{

    return 0;
}