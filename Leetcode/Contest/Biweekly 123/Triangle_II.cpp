#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        if (nums[0] == nums[1] && nums[0] == nums[2])
        {
            return "equilateral";
        }
        if ((nums[0] != nums[1] && nums[0] == nums[2]) || nums[0] == nums[1] && nums[0] != nums[2])
        {
            return "isosceles";
        }
        if (nums[0] + nums[1] <= nums[2])
        {
            return "none";
        }
        if (nums[1] + nums[2] <= nums[0])
        {
            return "none";
        }
        if (nums[0] + nums[2] <= nums[1])
        {
            return "none";
        }

        return "scalene";
    }
};

int main()
{

    return 0;
}