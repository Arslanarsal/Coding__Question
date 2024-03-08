#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int merge(vector<int> &a, int low, int mid, int high)
    {
        vector<int> temp;
        int i = low, j = mid + 1;
        int cnt = 0;
        int right = mid + 1;

        for (int k = low; k <= mid; k++)
        {
            while (right <= high && a[k] > 2 * 1LL * a[right])
            {
                right++;
            }
            cnt += right - (mid + 1);
        }

        while (i <= mid && j <= high)
        {
            if (a[i] <= a[j])
            {
                temp.push_back(a[i]);
                i++;
            }
            else
            {
                temp.push_back(a[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(a[i]);
            i++;
        }

        while (j <= high)
        {
            temp.push_back(a[j]);
            j++;
        }
        i = low;
        for (int i = 0; i < temp.size(); i++)
        {
            a[i + low] = temp[i];
        }
        return cnt;
    }

    int mergeSort(vector<int> &a, int low, int high)
    {
        int cnt = 0;
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;
            cnt += mergeSort(a, low, mid);
            cnt += mergeSort(a, mid + 1, high);
            cnt += merge(a, low, mid, high);
        }
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> v = {1, 3, 2, 3, 1};
    // cout << reversePairs(v);
    return 0;
}