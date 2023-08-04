#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxsum = INT_MIN;
    int size = nums.size();
    int cumarr[size + 1];
    cumarr[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        cumarr[i] = cumarr[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= size; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = cumarr[i] - cumarr[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int main()
{
    vector<int> v = {-1};
    cout << maxSubArray(v);

    return 0;
}