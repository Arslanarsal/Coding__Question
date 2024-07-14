#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({positions[i], i});
        }
        sort(v.begin(), v.end());
        bool flage = true;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || directions[v[i].second] == directions[st.top().second])
            {
                st.push({v[i].first, v[i].second});
            }
            else
            {
                while (!st.empty() && healths[st.top().second] < healths[v[i].second])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    healths[v[i].second]--;
                    st.push({v[i].first, v[i].second});
                }
                else if (healths[st.top().second] == healths[v[i].second])
                {
                    st.pop();
                }
                else
                {
                    healths[st.top().second]--;
                }
            }
        }
        if (st.empty())
        {
            return {};
        }
        int m = st.size();
        vector<int> ans(m);
        int i = 0;
        if (directions[st.top().second] == 'R')
        {
            while (!st.empty())
            {
                ans[i] = healths[st.top().second];
                i++;
                st.pop();
            }
        }
        else
        {
            while (!st.empty())
            {
                ans[m - i - 1] = healths[st.top().second];
                i++;
                st.pop();
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}