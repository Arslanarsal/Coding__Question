#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int boundary = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            boundary += nums[i];
            if (boundary == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}