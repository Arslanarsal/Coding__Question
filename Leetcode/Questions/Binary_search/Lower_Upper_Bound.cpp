#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, hight = n - 1;
    int ans = n;
    while (low < hight)
    {
        int mid = (low + hight) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            hight = mid;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
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

int main()
{

    return 0;
}