#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int start = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            start = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (start == -1)
    {
        return 0;
    }

    low = 0, high = n - 1;
    int end = -1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == x)
        {

            end = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return end - start + 1;
}

int main()
{

    vector<int> arr = {3, 3, 3};

    cout << count(arr, arr.size(), 3);

    return 0;
}