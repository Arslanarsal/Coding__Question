#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool find(vector<int> &piles, int mid, int k)
    {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ans += ceil((double)(piles[i]) / (double)(mid));
            if (ans > k)
            {
                return false;
            }
        }
        return true;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int high = *max_element(nums.begin(), nums.end());
        if (nums.size() == threshold)
        {
            return high;
        }
        int ans = 1;
        int low = 1;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (find(nums, mid, threshold))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}