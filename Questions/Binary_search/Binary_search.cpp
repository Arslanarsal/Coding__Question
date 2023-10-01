#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size() - 1;
    int min = 0;
    int max = n;
    if (target > nums[n])
    {
        return n + 1;
    }
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (nums[mid] == target)
        {

            return mid;
        }
        else if (nums[mid] > target)
        {
            max = mid - 1;
        }
        else if (nums[mid] < target)
        {
            min = mid + 1;
        }
    }
    return min;
}
int main()
{
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    cout << search(v, 2);

    return 0;
}