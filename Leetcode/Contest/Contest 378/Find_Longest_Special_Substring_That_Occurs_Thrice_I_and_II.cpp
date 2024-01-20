#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = 0;
        int count = 0;
        char pre = s[0];
        unordered_map<char, vector<int>> mp;
        for (auto &&i : s)
        {
            if (i == pre)
            {
                count++;
            }
            else
            {
                mp[pre].push_back(count);
                count = 1;
                pre = i;
            }
        }
        mp[pre].push_back(count);
        int ans = -1;
        for (auto &&i : mp)
        {
            char ch = i.first;
            vector<int> &vi = i.second;
            sort(vi.begin(), vi.end(), greater<int>());
            int l1 = 0, l2 = 0, l3 = 0;
            if (vi.size() >= 3)
            {
                l1 = vi[0];
                l2 = vi[1];
                l3 = vi[2];
            }
            else if (vi.size() == 2)
            {
                l1 = vi[0];
                l2 = vi[1];
            }
            else if (vi.size() == 1)
            {
                l1 = vi[0];
            }
            if (l1 == l2 && l3 < l1)
            {
                l2--;
            }
            if (l1 + l2 + l3 >= 3)
            {
                ans = max({ans, l1 - 2, l2});
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}