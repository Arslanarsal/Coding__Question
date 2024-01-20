#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int ans = 0;
        for (int i = 0; i < dimensions.size(); i++)
        {
            ans = max(ans, dimensions[i][0] * dimensions[i][1]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}