#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (ans < (points[i+1][0] - points[i][0]))
            {
                ans  = points[i+1][0] - points[i][0];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}