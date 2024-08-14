#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> dist(m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = abs(nums[i] - nums[j]);
                dist[d]++;
            }
        }

        for (int i = 0; i <= m; i++)
        {
            k -= dist[i];
            if (k <= 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}