#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto &&i : nums)
        {
            st.insert(i);
        }
        int ans = 1;
        for (auto &&i : nums)
        {
            if (st.find(i - 1) == st.end())
            {
                int cnt = 1;
                int x = i;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}