#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int max = nums.size() - 1;
    int min = 0;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == (nums.size() - 1) || nums[mid] >= nums[mid + 1]))
        {
            return mid;
        }
        else if (mid > 0 && nums[mid] < nums[mid - 1])
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2};
    cout << findPeakElement(v);

    return 0;
}