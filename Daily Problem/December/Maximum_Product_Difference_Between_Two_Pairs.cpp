#include <bits/stdc++.h>
using namespace std;

int maxProductDifference(vector<int> &nums)
{
    int n = nums.size();
    int idx = -1;
    int id = -1;
    int a = -1, b = -1;
    int c = INT_MAX, d = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > a)
        {
            idx = i;
            a = nums[i];
        }
        if (nums[i] < c)
        {
            id = i;
            c = nums[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > b && i != idx)
        {
            b = nums[i];
        }
        if (nums[i] < d && i != id)
        {
            d = nums[i];
        }
    }
    return (a * b) - (c * d);
}

int main()
{
    vector<int> v = {4, 2, 5, 9, 7, 4, 8};
    cout << maxProductDifference(v);

    return 0;
}