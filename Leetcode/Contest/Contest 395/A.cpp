#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        int a = *min_element(nums1.begin(), nums1.end());
        int b = *max_element(nums2.begin(), nums2.end());
        return b-a;
    }
};

int main()
{

    return 0;
}