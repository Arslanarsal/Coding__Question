#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int size = nums.size();
    int i;
    for (i = 1; i < size; i++)
    {
        if (nums[i] < nums[i - 1] && nums[i] <= nums[0])
        {
            break;
        }

        if (nums[i] < nums[i - 1])
        {
            return false;
        }
    }
    if (i == size - 1)
    {
        return true;
    }
    i++;
    while (i < size)
    {
        if (nums[i] < nums[i - 1] || nums[i] > nums[0])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    vector<int> v = {6,10,6};
    cout << check(v);

    return 0;
}