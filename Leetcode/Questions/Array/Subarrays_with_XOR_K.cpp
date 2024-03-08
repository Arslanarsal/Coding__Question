#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b)
{
    int n = a.size();
    map<int, int> mp;
    mp[0] = 1;
    int pre = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        pre ^= a[i];
        int x = pre ^ b;
        ans += mp[x];
        mp[pre]++;
    }
    return ans;
}

int main()
{

    return 0;
}