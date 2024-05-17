#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = n - k - 1; i >= 0; i--)
        {
            arr[i] += arr[i + k];
        }
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}