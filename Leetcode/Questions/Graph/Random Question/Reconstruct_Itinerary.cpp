#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> mp;
        for (auto &&it : tickets)
        {
            mp[it[0]].insert(it[1]);
        }

        vector<string> ans;
        stack<string> st;
        st.push("JFK");

        while (!st.empty())
        {
            string top = st.top();
            if (mp[top].empty())
            {
                ans.push_back(top);
                st.pop();
            }
            else
            {
                st.push(*mp[top].begin());
                mp[top].erase(mp[top].begin());
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}