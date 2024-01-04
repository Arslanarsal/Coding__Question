#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool ispossible(int mid, unordered_map<char, vector<int>> &mp)
    {
        int count = 0;
        for (auto &&[key, value] : mp)
        {
            count = 0;
            for (auto &&i : value)
            {
                count += max(0, i - mid + 1);
            }
            if (count >= 3)
            {
                return true;
            }
        }
        return false;
    }

public:
    int maximumLength(string s)
    {
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        int lastchar = s[0], count = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == lastchar)
            {
                count++;
            }
            else
            {
                mp[lastchar].push_back(count);
                lastchar = s[i];
                count = 1;
            }
        }
        mp[lastchar].push_back(count);
        int ans = -1;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (ispossible(mid, mp))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    // cout << maximumLength("");
    return 0;
}