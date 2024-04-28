#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = INT_MIN;
        stack<int> s;
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[i] <= heights[s.top()]))
            {
                int hi = heights[s.top()];
                s.pop();
                int wid;
                if (s.empty())
                {
                    wid = i;
                }
                else
                {
                    wid = i - s.top() - 1;
                }
                ans = max(ans, hi * wid);
            }
            s.push(i);
        }
        return ans;
    }
};

int main()
{

    return 0;
}