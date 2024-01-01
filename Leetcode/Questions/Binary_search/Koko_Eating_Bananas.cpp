#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &piles)
{
    int ans = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        ans = max(ans, piles[i]);
    }
    return ans;
}
int findH(vector<int> &piles, int mid)
{
    
    if (mid == 0)
        return INT_MAX; 

    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += ceil((double)piles[i] / (double)mid);
    }
    return ans;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int min = 0, mid;
    int max = fun(piles);
    while (min <= max)
    {
        mid = (min + max) / 2;
        int total = findH(piles, mid);
        if (total <= h)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return min;
}

int main()
{
    vector<int> v = {30, 11, 23, 4, 20};
    cout << minEatingSpeed(v, 6);

    return 0;
}