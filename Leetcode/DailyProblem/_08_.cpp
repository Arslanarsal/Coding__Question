#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
<<<<<<< HEAD
        vector<vector<int>> ans;
        vector<bool> rowCheck(rows , false) , colCheck(cols , false);
        bool right = true , bottom = true , left = true , top = true;
        
=======
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
>>>>>>> 612afbf91b3e5e60d4bf1d147177866db4ca57f6
    }
};

int main()
{

    return 0;
}