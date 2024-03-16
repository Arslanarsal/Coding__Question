#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> &stalls, int &dis, int k)
{
    int pre = stalls[0];
    k--;
    int n = stalls.size();
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - pre >= dis)
        {
            pre = stalls[i];
            k--;
        }
        if (k == 0)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = stalls[0];
    int high = stalls[n - 1];
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (find(stalls, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}