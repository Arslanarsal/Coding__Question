#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        st.push({temperatures[0], 0}); // 30 40 50 60
        for (int i = 1; i < n; i++)
        {
            if (st.top().first > temperatures[i])
            {
                st.push({temperatures[i], i});
            }
            else
            {
                while (!st.empty() && st.top().first < temperatures[i])
                {
                    ans[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({temperatures[i], i});
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}