#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<int> l = intervals[0];

        int n = intervals.size();
        int i = 1;
        int ans = 0;
        while (i < n)
        {
            int le = l[1];

            int cs = intervals[i][0];
            int ce = intervals[i][1];

            if (cs >= le)
            {
                l = intervals[i];
            }
            else if (ce > le)
            {
                ans++;
            }
            else
            {
                l = intervals[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}