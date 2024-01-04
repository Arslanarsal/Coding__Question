#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1, ans = 0;
    int leftmax = height[left];
    int rightmax = height[right];
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= leftmax)
            {
                leftmax = height[left];
            }
            else
            {
                ans += (leftmax - height[left]);
            }
            left++;
        }
        else
        {
            if (height[right] >= rightmax)
            {
                rightmax = height[right];
            }
            else
            {
                ans += (rightmax - height[right]);
            }
            right--;
        }
    }
    return ans;
}

long long getTrappedWater(long long* height, int n) {
    int left = 0, right = n - 1;
    long long ans = 0;
    long long leftmax = height[left];
    long long rightmax = height[right];
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= leftmax)
            {
                leftmax = height[left];
            }
            else
            {
                ans += (leftmax - height[left]);
            }
            left++;
        }
        else
        {
            if (height[right] >= rightmax)
            {
                rightmax = height[right];
            }
            else
            {
                ans += (rightmax - height[right]);
            }
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> v ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v);

    return 0;
}