#include <bits/stdc++.h>
using namespace std;

// int mergesort(vector<int> &nums, int min, int max)
// {
//     if (min == max)
//     {
//         return 0;
//     }
//     int ans = 0;
//     int mid = (min + max) / 2;
//     ans += mergesort(nums, min, mid);
//     ans += mergesort(nums, min + 1, max);
//     int i = min, j = mid + 1, count = 0;
//     while (i <= mid && j <= max)
//     {
//         if (nums[i] > nums[j] * 2)
//         {
//             count++;
//             j++;
//         }
//         else
//         {
//             ans += count;
//             i++;
//         }
//     }
//     while (i <= mid && j > max)
//     {
//         if (nums[i] > nums[j - 1] * 2)
//         {
//             ans += count;
//             i++;
//         }
//     }
//     j = mid + 1;
//     for (int i = min; i < mid; i++)
//     {
//         if (nums[i] > nums[j])
//         {
//             swap(nums[i], nums[j]);
//             j++;
//         }
//         if (nums[i] == nums[j])
//         {
//             swap(nums[i], nums[j]);
//         }
//     }
//     return ans;
// }

void merge(vector<int> arr, int low, int mid, int high)
{

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int a[n1], b[n2];

    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        a[i] = arr[low + i];
    }

    for (i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }

    i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

int mergeSort(vector<int> arr, int start, int end)
{
    int mid;
    if (start < end)
    {
        int ans = 0;
        mid = (start + end) / 2;
        ans += mergeSort(arr, start, mid);
        ans += mergeSort(arr, mid + 1, end);
        int i = start, j = mid + 1, count = 0;
        while (i <= mid && j <= end)
        {
            if (arr[i] > arr[j] * 2)
            {
                count++;
                j++;
            }
            else
            {
                ans += count;
                i++;
            }
        }
        while (i <= mid && j > end)
        {
            if (arr[i] > arr[j - 1] * 2)
            {
                ans += count;
            }
            else
            {
                break;
            }
            i++;
        }
        merge(arr, start, mid, end);
        return ans;
    }
    return 0;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> v = {1, 3, 2, 3, 1};
    cout << reversePairs(v);
    return 0;
}