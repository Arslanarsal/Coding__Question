#include <bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    long long presum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        if (mp.find(presum) != mp.end())
        {
            ans = max(ans, i - mp[presum]);
        }
        if (mp.find(presum) == mp.end())
        {
            mp[presum] = i;
        }
    }
    return ans;
}

int main()
{

    return 0;
}