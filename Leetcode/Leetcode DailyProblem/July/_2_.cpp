#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1, mp2;
        for (auto &&it : nums1)
        {
            mp1[it]++;
        }
        for (auto &&it : nums2)
        {
            mp2[it]++;
        }
        vector<int> ans;
        for (auto &&it : mp1)
        {
            if (mp2.count(it.first))
            {

                int n = min(mp1[it.first], mp2[it.first]);
                ans.insert(ans.end(), n, it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}