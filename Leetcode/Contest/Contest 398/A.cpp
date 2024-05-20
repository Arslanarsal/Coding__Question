#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if ((nums[i] & 1) == (nums[i - 1] & 1))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}