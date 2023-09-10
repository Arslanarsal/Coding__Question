#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 1)
            count = 0;
        else
        {
            count++;
            maxi = max(count, maxi);
        }
    }
    return maxi;
}

int main()
{
    vector<int> v = {1, 0, 1, 1, 0, 1};
    cout << findMaxConsecutiveOnes(v);

    return 0;
}