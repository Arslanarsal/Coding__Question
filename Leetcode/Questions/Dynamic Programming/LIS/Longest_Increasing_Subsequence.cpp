#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        int ans = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                ans++;
            }
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        for (auto &&j : temp)
        {
            cout << j << " ";
        }
        cout << "\n\n\n";
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}

// TC = O(N * log N) - N binary searches of O(log N) each
// SC = O(N)

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         vector<int> temp;
//         temp.push_back(nums[0]);
//         int l = 1; // len = 1 as we pushed nums[0]
//         // LOGIC : Create a temp array that adds elements if greater than the last element, and if not, overwrites smallest greater element. NOTE : temp does not store the longest increasing subsequence, we are just utilizing the length of temp to get our answer.
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (temp.back() < nums[i])
//             { // If nums[i] is greater, just add it at the back
//                 temp.push_back(nums[i]);
//                 l++;
//             }
//             else
//             {                                                                            // If not, just replace the smallest element greater than nums[i] with nums[i]
//                 int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); // inbuilt c++ function to perform binary search O(log N) to search for the third parameter in the array or element just greater than it. Do - temp.begin() to get an integer index value
//                 temp[ind] = nums[i];
//             }
//         }
//         return l;
//     }
// };