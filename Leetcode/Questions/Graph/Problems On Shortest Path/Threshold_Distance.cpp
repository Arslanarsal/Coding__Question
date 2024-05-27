#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto &&it : edges)
        {
            mat[it[0]][it[1]] = it[2];
        }
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
        for (int v = 0; v < n; v++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][v] != INT_MAX && mat[v][j] != INT_MAX)
                    {
                        mat[i][j] = min(mat[i][j], mat[i][v] + mat[v][j]);
                    }
                }
            }
        }
        int ans = 0;
        int pre = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] < distanceThreshold)
                {
                    temp++;
                }
            }
            if (temp <= pre)
            {
                ans = i;
                pre = temp;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}