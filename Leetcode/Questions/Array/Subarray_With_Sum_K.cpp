#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    int ans = 0;
    unordered_map<int, int> ch;
    ch[0] = 0;
    ch[a[0]] = 0;
    if (a[0] == k)
    {
        ans++;
    }
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
        if (a[i] == k || (a[i] > k && ch.find(a[i] - k) != ch.end()))
        {
            ans = max(ans, i - ch[a[i] - k]);
        }
        ch[a[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1};
    cout << longestSubarrayWithSumK(v, 3);

    return 0;
}