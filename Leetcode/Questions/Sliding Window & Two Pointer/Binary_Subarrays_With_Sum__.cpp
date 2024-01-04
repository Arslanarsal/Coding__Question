#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the size of the string.
*/

int subarrayWithSum(vector<int> &arr, int k)
{

    // To store the result.
    int res = 0;

    // To store count of '1s'.
    int cnt = 0;

    // To store prefix sum.
    vector<int> prefix(arr.size() + 1, 0);

    // Initialize index having zero sum as 1.
    prefix[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {

        // Update count.
        cnt += arr[i];

        // Check condition.
        if (cnt >= k)
        {

            // Update result.
            res += prefix[cnt - k];
        }

        // Update prefix array.
        prefix[cnt]++;
    }

    return res;
}
int main()
{
    vector<int> v = {1, 0, 1, 0, 1};
    cout << subarrayWithSum(v, 2);

    return 0;
}