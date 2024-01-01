#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int head, tail = 0, sum = 0, ans = INT_MAX;
    for (head = 0; head < nums.size(); head++)
    {
        sum += nums[head];
        while (sum >= target)
        {
            int temp = head - tail + 1;
            ans = min(ans, temp);
            sum -= nums[tail++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int minSubarraySum(int nums[], int n, int target)
{
    int head = 0, tail = 0, sum = 0, ans;

    while (head < target)
    {
        sum += nums[head];
        head++;
    }
    ans = sum;
    for (head = target; head < n; head++)
    {
        sum -= nums[tail++];
        sum += nums[head];
        if (sum < ans)
        {
            ans = sum;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 4, 4};
    cout << minSubArrayLen(4, v) << endl;
    return 0;
}