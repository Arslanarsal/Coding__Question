#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool canDivide(int maxSum, int k, const vector<int> &arr)
{
    int subarrayCount = 1; // We need at least one subarray
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currentSum + arr[i] > maxSum)
        {
            subarrayCount++;     // Start a new subarray
            currentSum = arr[i]; // Initialize it with the current element
            if (subarrayCount > k)
            {
                return false; // We need more subarrays than allowed
            }
        }
        else
        {
            currentSum += arr[i]; // Continue adding to the current subarray
        }
    }

    return true;
}

int32_t main()
{
    fastio;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    int maxElement = 0;
    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]); // The minimum possible max sum is the largest element
        totalSum += arr[i];                   // The maximum possible max sum is the total sum
    }

    int low = maxElement;
    int high = totalSum;
    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canDivide(mid, k, arr))
        {
            result = mid;   // Try to minimize the maximum sum
            high = mid - 1; // Try smaller sums
        }
        else
        {
            low = mid + 1; // Try larger sums
        }
    }

    cout << result << "\n";

    return 0;
}
