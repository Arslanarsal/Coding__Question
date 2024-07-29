#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dotX[4] = {-1, 0, 1, 0};
    int dotY[4] = {0, 1, 0, -1};
    int dotXd[4] = {1, 1, -1, -1};
    int dotYd[4] = {-1, 1, 1, -1};

    bool solve(int x, int y, vector<vector<bool>> &cir, vector<vector<bool>> &vist)
    {
        if (x < 0 || y < 0 || x >= cir.size() || y >= cir[0].size() || vist[x][y] || !cir[x][y])
        {
            return false;
        }

        if (x == cir.size() - 1 && y == cir[0].size() - 1)
        {
            return true;
        }
        vist[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dotXd[i];
            int newy = y + dotYd[i];
            if (newx >= 0 && newx < cir.size() && newy >= 0 && newy < cir[0].size() && cir[newx][newy] && solve(newx, newy, cir, vist))
            {
                return true;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dotX[i];
            int newy = y + dotY[i];
            if (newx >= 0 && newx < cir.size() && newy >= 0 && newy < cir[0].size() && cir[newx][newy] && solve(newx, newy, cir, vist))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool canReachCorner(int X, int Y, vector<vector<int>> &circles)
    {
        vector<vector<bool>> cir(X, vector<bool>(Y, 1));
        for (auto &&it : circles)
        {
            int x = it[0] - 1;
            int y = it[1] - 1;
            int r = it[2];
            if (r == 0)
            {
                continue;
            }
            int top = max(0, x - (r - 1));
            int right = min(Y, y + r + 1);
            int bottom = min(X, x + r + 1);
            int left = max(0, y - (r - 1));
            for (int i = top; i < bottom; i++)
            {
                for (int j = left; j < right; j++)
                {
                    cir[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                cout << cir[i][j] << " ";
            }
            cout << endl;
        }
        vector<vector<bool>> vist(X, vector<bool>(Y, false));
        // cout << solve(0, 0, cir, vist);
        return solve(0, 0, cir, vist);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> circles = {{3, 1, 1}, {8, 3, 1}, {12, 2, 1}, {6, 4, 1}, {6, 4, 1}, {4, 3, 1}, {5, 4, 1}};
    int X = 13, Y = 5;
    // sol.canReachCorner(X, Y, circles);
    cout << boolalpha << sol.canReachCorner(X, Y, circles) << endl;
    return 0;
}