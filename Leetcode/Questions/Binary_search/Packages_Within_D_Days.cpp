#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool check(vector<int> &weights, long long mid, int days)
    {
        long long sum = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            if (sum + weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                sum = 0;
                days--;
                if (weights[i] > mid || days == 0)
                {
                    return false;
                }
                sum += weights[i];
            }
        }
        return true;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        int ans = 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(weights, mid, days))
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