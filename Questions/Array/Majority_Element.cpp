#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int ele, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0 || ele == nums[i])
        {
            ele = nums[i];
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ele == nums[i])
        {
            count++;
        }
    }
    if (count > (nums.size() / 2))
    {
        return ele;
    }
    return -1;
}

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2, 1, 1, 3};
    cout << majorityElement(v);

    return 0;
}