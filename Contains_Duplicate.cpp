#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> us;
        for (auto num : nums)
        {
            if (us.count(num) > 0)
            {
                return true;
            }
            us.insert(num);
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    cout << s.containsDuplicate(v);

    return 0;
}