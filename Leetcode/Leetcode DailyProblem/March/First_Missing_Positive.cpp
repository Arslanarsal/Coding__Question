#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    bool one = true;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            one = false;
        }
        if (nums[i] < 2)
        {
            nums[i] = 0;
        }
    }
    if (one)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0 && nums[i] != -1 && nums[i] <= n)
        {
            int num = abs(nums[i]);

            if (nums[num - 1] == 0 || nums[num - 1] == -1)
            {
                nums[num - 1] = -1;
            }
            else
            {
                if (nums[num - 1] > 0)
                {
                    nums[num - 1] *= -1;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == 0 || nums[i] > 0)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main()
{
    vector<int> v = {1};
    cout << firstMissingPositive(v);

    return 0;
}