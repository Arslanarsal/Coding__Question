#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = 0, value;
        int n = colors.size();
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                res += min(neededTime[i], neededTime[i - 1]);
                value = max(neededTime[i], neededTime[i - 1]);
                while (i < n - 1 && colors[i] == colors[i + 1])
                {
                    res += min(value, neededTime[i + 1]);
                    value = max(value, neededTime[i + 1]);
                    i++;
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}