#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> f;
        for (auto &&el : arr)
        {
            f[el]++;
        }
        multiset<int> s;
        for (auto &&el : f)
        {
            // cout << el.second << "   df\n";

            s.insert(el.second);
        }
        n = s.size();
        int i = 0;
        for (auto &&f : s)
        {
            // cout << f << "\n";
            k -= f;

            if (k < 0)
            {
                return n - i;
            }
            i++;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {4, 3, 1, 1, 3, 3, 2};
    cout << sol.findLeastNumOfUniqueInts(v, 3);

    return 0;
}