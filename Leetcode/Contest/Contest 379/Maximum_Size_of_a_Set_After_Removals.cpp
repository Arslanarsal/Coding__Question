#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        unordered_set<int> s1, s2, common;
        for (auto &&i : nums1)
        {
            s1.insert(i);
        }
        for (auto &&i : nums2)
        {
            s2.insert(i);
            if (s1.find(i) != s1.end())
            {
                common.insert(i);
            }
        }
        int n1 = s1.size(), n2 = s2.size(), c = common.size();
        return min(n, min(n1 - c, n / 2) + min(n2 - c, n / 2) + c);
    }
};

int main()
{

    return 0;
}