#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> &arr, int &mid, int &n, int m)
{
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre + arr[i] > mid)
        {
            pre = 0;
            m--;
        }
        if (m == 0)
        {
            return true;
        }
        pre += arr[i];
    }
    return false;
}

int findPages(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;
    if (n < m)
    {
        return -1;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (find(arr, mid, n, m))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << low << "  " << high;
    return ans;
}

int main()
{
    vector<int> v = {12, 34, 67, 90};
    findPages(v, 4, 2);

    return 0;
}