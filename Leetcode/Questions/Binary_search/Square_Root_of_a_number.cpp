#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    int low = 1, high = n;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
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
    cout << floorSqrt(15);

    return 0;
}