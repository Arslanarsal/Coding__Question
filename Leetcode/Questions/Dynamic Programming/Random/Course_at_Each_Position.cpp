#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        vector<int> temp;
        temp.push_back(obstacles[0]);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {

            if (temp.back() <= obstacles[i])
            {
                temp.push_back(obstacles[i]);
                ans[i] = temp.size();
            }
            else
            {
                int lower = (upper_bound(temp.begin(), temp.end(), obstacles[i])) - temp.begin();
                temp[lower] = obstacles[i];
                ans[i] = lower + 1;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> res(n, 1);
        vector<int> lis;
        lis.push_back(obstacles[0]);
        for (int i = 1; i < n; i++)
        {
            if (lis.back() <= obstacles[i])
            {
                lis.push_back(obstacles[i]);
                res[i] = lis.size();
            }
            else
            {
                int idx = (upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin());
                lis[idx] = obstacles[i];
                res[i] = idx + 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 2};
    Solution sol;
    sol.longestObstacleCourseAtEachPosition(v);

    return 0;
}