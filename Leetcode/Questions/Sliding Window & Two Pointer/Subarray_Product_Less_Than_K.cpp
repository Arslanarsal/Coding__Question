#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int head, tail = 0, prod = 1, ans = 0;
    for (head = 0; head < nums.size(); head++)
    {
        prod = prod * nums[head];
        while (prod >= k && tail<=head)
        {
            prod = prod / nums[tail++];
        }
        ans += head - tail + 1;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    cout << numSubarrayProductLessThanK(nums, 0);

    return 0;
}