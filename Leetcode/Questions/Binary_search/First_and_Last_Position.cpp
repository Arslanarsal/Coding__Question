#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] >= k)
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

int upperbound(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] > k)
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

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerbound(arr, n, k);
    if (lb == -1 || arr[lb] != k)
    {
        return {-1, -1};
    }
    int up = upperbound(arr, n, k) - 1;
    return {lb, up};
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2};
    firstAndLastPosition(arr, arr.size(), 2);

    return 0;
}