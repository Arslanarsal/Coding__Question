#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N)
    Space complexity: O(1)

    where 'N' is the total number of elements in the array.
*/

int longestSubSeg(vector<int> &arr, int n, int k)
{

    // Stores count of zero in the array under consideration.
    int cnt0 = 0;
    int l = 0;
    int maxLen = 0;

    // r decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            cnt0++;
        }

        // If there are more 0's move left pointer towards current ending point.
        while (cnt0 > k)
        {
            if (arr[l] == 0)
            {
                cnt0--;
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main()
{
    vector<int> v = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    // cout << longestOnes(v, 2);
    int n = v.size();
    cout << longestSubSeg(v, n, 2);

    return 0;
}