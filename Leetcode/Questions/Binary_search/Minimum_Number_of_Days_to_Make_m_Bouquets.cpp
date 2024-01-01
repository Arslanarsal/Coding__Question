#include <bits/stdc++.h>
using namespace std;

int highele(vector<int> &bloomDay)
{
    int ans = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        ans = max(ans, bloomDay[i]);
    }
    return ans;
}

bool ismakeBouq(vector<int> &bloomDay, int &mid, int &m, int &k)
{
    int count = 0, ans = 0;

    for (int i = 0; i < bloomDay.size() - 1; i++)
    {
        if (bloomDay[i] <= mid)
        {
            count++;
        }
        if (count >= k)
        {
            ans++;
            count = 0;
        }
        else if (bloomDay[i + 1] > mid)
        {
            count = 0;
        }
    }
    if (bloomDay[bloomDay.size() - 1] <= mid)
    {
        count++;
    }
    if (count >= k)
    {
        ans++;
    }
    if (ans >= m)
    {
        return true;
    }
    return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int low = 0;
    int high = highele(bloomDay);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ismakeBouq(bloomDay, mid, m, k))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{
    vector<int> v = {7, 7, 7, 7, 12, 7, 7};
    cout << minDays(v, 2, 3);
    return 0;
}