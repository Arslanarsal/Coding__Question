#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            cnt += (mid - i + 1);
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

int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> v = {1, 4, 7, 5, 4, 2, 2, 1, 0};
    mergeSort(v, 0, v.size() - 1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}