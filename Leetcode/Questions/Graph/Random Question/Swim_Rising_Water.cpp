#include <bits/stdc++.h>
using namespace std;



class Solution
{
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        visit[0][0] = true;
        while (!pq.empty())
        {
            auto [h, dir] = pq.top();
            pq.pop();
            int i = dir.first;
            int j = dir.second;
            if (i == n - 1 && j == n - 1)
            {
                return h;
            }
            for (int k = 0; k < 4; k++)
            {
                int ni = i + x[k];
                int nj = j + y[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visit[ni][nj])
                {
                    visit[ni][nj] = true;
                    pq.push({max(h, grid[ni][nj]), {ni, nj}});
                }
            }
        }
        return -1;
    }
};



int main()
{

    return 0;
}