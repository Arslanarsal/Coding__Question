#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int num1 = 0;
        int num2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 9)
            {
                num1 += nums[i];
            }
            else
            {
                num2 += nums[i];
            }
        }
        return num1 == num2;
    }
};

int main()
{

    return 0;
}