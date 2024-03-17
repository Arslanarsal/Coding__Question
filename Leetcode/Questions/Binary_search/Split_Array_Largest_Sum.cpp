#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int find(vector<int> &nums, int mid, int k)
    {
        int parti = 0;
        long long maxsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxsum + nums[i] <= mid)
            {
                maxsum += nums[i];
            }
            else
            {
                parti++;
                maxsum = nums[i];
            }
        }
        return parti;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;
            cout << "Mid  ->  " << mid << endl;
            int x = find(nums, mid, k);
            if (x >= k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> v = {7, 2, 5, 10, 8};

    Solution sol;
    cout << sol.splitArray(v, 2);
    return 0;
}
