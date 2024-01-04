#include <bits/stdc++.h>
using namespace std;

vector<int> numberGame(vector<int> &nums)
{
    int n = nums.size();
    if (n < 1)
    {
        return nums;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n /2; i++)
    {
        int first = nums[0];
        int second = nums[1];
        auto it = nums.begin();
        nums.erase(it);
        it = nums.begin();
        nums.erase(it);
        nums.push_back(second);
        nums.push_back(first);
    }
    return nums;
}


int main()
{
    vector<int> nums = {2, 5};
    nums = numberGame(nums);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }

    return 0;
}