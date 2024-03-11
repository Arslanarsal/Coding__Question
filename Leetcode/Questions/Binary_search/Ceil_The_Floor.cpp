#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int low = 0, hight = n - 1;
    int ans = -1;
    while (low <= hight)
    {
        int mid = (low + hight) / 2;
        if (a[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            hight = mid - 1;
        }
    }
    if (ans == -1)
    {
        return {-1, a[0]};
    }
    if (a[ans] == x)
    {
        return {x, x};
    }
    if (ans == n - 1)
    {
        return {a[ans], -1};
    }
    return {a[ans], a[ans + 1]};
}

int main()
{
    vector<int> arr = {1, 3, 5, 7};
    int n = arr.size();
    pair<int, int> a = getFloorAndCeil(arr, n, 0);
    cout << a.first << " " << a.second;

    return 0;
}