#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int &target)
    {
        int mid, start = 0, end = (nums.size() - 1);
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] >= nums[start])
            {
                if (nums[start] <= target && nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[end] >= target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 1, 3};
    int target = 5;
    cout << s.search(nums, target);
    return 0;
}