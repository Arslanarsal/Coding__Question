#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums[nums.size() - 1] - 1;
        int m = nums[nums.size() - 2] - 1;
        return n * m;
    }
};

int main()
{

    return 0;
}